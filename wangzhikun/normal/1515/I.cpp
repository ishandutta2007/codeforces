/*
    Author: Zhikun Wang
*/
 
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cout << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cout << " " << to_string(H);  debug_out(T...);}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//#define debug(...) 42
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

#define mid ((l+r)/2)

int n,q,a[200020],w[200020],v[200020];

int id[200020],rid[200020];

ll aa[200020],vv[200020],ww[200020];
const int SZ = 19;
ll sv[525000][SZ],sw[525000][SZ];
ll S[525000][SZ];

inline int l2(ll x){
    return __lg(x)+1;
}
ll inf;
void build_tree(int l,int r,int id){
    if(l == r){
        int c = l2(ww[l]);
        for(int i=c;i<SZ;i++){
            sv[id][i] = aa[l]*vv[l];
            sw[id][i] = aa[l]*ww[l];
        }
        if(aa[l])S[id][c]=ww[l];
        return;
    }
    build_tree(l,mid,id*2);
    build_tree(mid+1,r,id*2+1);
    for(int i=1;i<SZ;i++){
        sw[id][i] = sw[id*2][i]+sw[id*2+1][i];
        sv[id][i] = sv[id*2][i]+sv[id*2+1][i];
        S[id][i] = min(S[id*2][i]+sw[id*2+1][i-1],S[id*2+1][i]);
    }
}

void op(int l,int r,int id,int q,int ch){
    if(l == r){
        pii ret;
        int c = l2(ww[l]);
        aa[l]+=ch;
        for(int i=c;i<SZ;i++){
            sv[id][i] = aa[l]*vv[l];
            sw[id][i] = aa[l]*ww[l];
        }
        S[id][c]=inf;
        if(aa[l])S[id][c]=ww[l];
        return;
    }
    if(q<=mid)op(l,mid,id*2,q,ch);
    else op(mid+1,r,id*2+1,q,ch);
    for(int i=1;i<SZ;i++){
        sw[id][i] = sw[id*2][i]+sw[id*2+1][i];
        sv[id][i] = sv[id*2][i]+sv[id*2+1][i];
        S[id][i] = min(S[id*2][i]+sw[id*2+1][i-1],S[id*2+1][i]);
    }
}

pll query(int l,int r,int id,ll rem){
    if(rem == 0)return MP(0,0);
    if(l == r){
        ll cnt = min(aa[l],(rem/ww[l]));
        return MP(cnt*vv[l],rem-cnt*ww[l]);
    }
    int c = min(SZ-1,l2(rem));
    int ok = 0;
    if(S[id][c]<=rem)ok = 1;
    if(!ok && rem>=sw[id][c-1])
        return MP(sv[id][c-1],rem-sw[id][c-1]);
    pll ret = query(mid+1,r,id*2+1,rem);
    pll cc = query(l,mid,id*2,ret.S);
    ret.S = cc.S; ret.F+=cc.F;
    return ret;
}

int main(){
    memset(S,15,sizeof(S)); inf = S[0][0];
    read(n,q);
    vector<pair<pii,int>> V;
    for(int i=1;i<=n;i++){
        read(a[i],w[i],v[i]);
        V.PB(MP(MP(v[i],-w[i]),i));
    }
    sort(all(V));
    for(int i=0;i<n;i++){
        id[V[i].S] = i;
        rid[i] = V[i].S;
        aa[i] = a[V[i].S];
        vv[i] = v[V[i].S];
        ww[i] = w[V[i].S];
    }
    build_tree(0,n-1,1);
    int t,k,d;
    for(int i=0;i<q;i++){
        read(t);
        if(t == 1){
            read(d,k);
            op(0,n-1,1,id[k],d);
        }
        if(t == 2){
            read(d,k);
            op(0,n-1,1,id[k],-d);
        }
        if(t == 3){
            ll lim;
            read(lim);
            pll t = query(0,n-1,1,lim);
            cout<<t.F<<"\n";
        }
    }
    return 0;
}