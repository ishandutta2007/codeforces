/*
 Author: Zhikun Wang
 */

#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

int mi[800080],mx[800080];
ll sm[800080];
int n,q,a[200020],t,x,y;

#define mid ((l+r)/2)
void build_tree(int id,int l,int r){
    if(l == r){
        mi[id] = mx[id] = sm[id] = a[l];
        return;
    }
    build_tree(id*2,l,mid);
    build_tree(id*2+1,mid+1,r);
    mi[id] = min(mi[id*2],mi[id*2+1]);
    mx[id] = max(mx[id*2],mx[id*2+1]);
    sm[id] = sm[id*2]+sm[id*2+1];
    debug(id,sm[id]);
}

void pb(int id,int l,int r){
    if(mi[id] == mx[id]){
        mi[id*2] = mx[id*2] = mi[id];
        mi[id*2+1] = mx[id*2+1] = mi[id];
        sm[id*2] = 1ll*mi[id]*(mid+1-l);
        sm[id*2+1] = 1ll*mi[id]*(r-mid);
    }
}

void q1(int id,int l,int r,int ed,int v){
    debug(id,l,r,ed,v,mi[id],mx[id]);
    if(r>ed){
        pb(id,l,r);
        if(ed>=l)q1(id*2,l,mid,ed,v);
        if(ed>=mid+1)q1(id*2+1,mid+1,r,ed,v);
        mi[id] = min(mi[id*2],mi[id*2+1]);
        mx[id] = max(mx[id*2],mx[id*2+1]);
        sm[id] = sm[id*2]+sm[id*2+1];
        return;
    }
    debug(0);
    if(v<=mi[id])return;
    
    debug(3);
    if(v>=mx[id]){
        debug(id);
        mx[id] = mi[id] = v;
        sm[id] = 1ll*(r-l+1)*v;
        return;
    }
    pb(id,l,r);
    if(mi[id*2]<v){
        q1(id*2,l,mid,ed,v);
        debug(1);
    }
    debug(1);
    q1(id*2+1,mid+1,r,ed,v);
    debug(2);
    mi[id] = min(mi[id*2],mi[id*2+1]);
    mx[id] = max(mx[id*2],mx[id*2+1]);
    sm[id] = sm[id*2]+sm[id*2+1];
    debug(id,mx[id],mi[id],sm[id]);
}

ll qsum(int id,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr)return sm[id];
    pb(id,l,r);
    ll ret = 0;
    if(ql<=mid)ret+=qsum(id*2,l,mid,ql,qr);
    if(qr>mid)ret+=qsum(id*2+1,mid+1,r,ql,qr);
    return ret;
}

pair<ll,int> q2(int id,int l,int r,ll cs){
    debug(id,l,r,cs,sm[id]);
    if(cs>=sm[id])return MP(cs-sm[id],r-l+1);
    if(l == r || cs<mi[id])return MP(cs,0);
    pb(id,l,r);
    int ans = 0;
    if(cs>=mi[id*2]){
        pair<ll,int> C = q2(id*2,l,mid,cs);
        cs = C.F;
        ans+=C.S;
    }
    if(cs>=mi[id*2+1]){
        pair<ll,int> C = q2(id*2+1,mid+1,r,cs);
        cs = C.F;
        ans+=C.S;
    }
    return MP(cs,ans);
}

int main() {
    read(n,q);
    for(int i=1;i<=n;i++)read(a[i]);
    build_tree(1,1,n);
    for(int i=1;i<=q;i++){
        read(t,x,y);
        if(t == 1){
            q1(1,1,n,x,y);
        }else{
            ll cs = 0;
            if(x!=1)cs = qsum(1,1,n,1,x-1);
            cout<<q2(1,1,n,cs+y).S-x+1<<"\n";
        }
    }
    return 0;
}