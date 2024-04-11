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

int T,n,l,r,c;

int main(){
    cin>>T;
    while(T--){
        cin>>n>>l>>r;
        vector<int> cnt(n+5,0);
        for(int i=0;i<l;i++){
            cin>>c;
            cnt[c]+=1;
        }
        for(int i=0;i<r;i++){
            cin>>c;
            cnt[c]-=1;
        }
        int ans = 0;
        int j0 = 0,j1 = 0,s0 = 0,s1 = 0;
        for(int i=1;i<=n;i++){
            if(cnt[i]>0 && ((cnt[i]%2)!=0))j0+=1;
            if(cnt[i]<0 && ((cnt[i]%2)!=0))j1+=1;
            if(cnt[i]>0)s0+=cnt[i];
            if(cnt[i]<0)s1-=cnt[i];
        }
        int c = min(j0,j1);
        ans+=c;
        j0-=c;s0-=c;
        j1-=c;s1-=c;
        c = min(j0,s1);ans+=c;
        j0-=c;s0-=c;
        s1-=c;
        c = min(j1,s0);ans+=c;
        s0-=c;
        j1-=c;s1-=c;
        if(j1>0){
            ans+=j1;s1-=j1;
            j1 = 0;
        }
        if(j0>0){
            ans+=j0;s0-=j0;
            j0 = 0;
        }
        ans+=(s1+s0)/2;
        cout<<ans<<endl;
    }
    return 0;
}