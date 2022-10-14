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

int T,n,m,x[300020],ans[300020];
vector<pair<int,pair<char,int>>> V;
void solve(){
    V.clear();
    read(n,m);
    for(int i=0;i<n;i++){
        read(x[i]);
        ans[i] = -1;
    }
    for(int i=0;i<n;i++){
        char S;
        cin>>S;
        V.PB(MP(x[i],MP(S,i)));
    }
    sort(all(V));
    deque<pii> A[2];
    for(int i=0;i<n;i++){
        if(V[i].S.F == 'R'){
            A[V[i].F%2].PB(MP(V[i].F,V[i].S.S));
        }else{
            if(A[V[i].F%2].size()){
                auto C = A[V[i].F%2].back();A[V[i].F%2].pop_back();
                ans[V[i].S.S] = ans[C.S] = (V[i].F-C.F)/2;
            }else{
                A[V[i].F%2].PB(MP(-V[i].F,V[i].S.S));
            }
        }
    }
    for(int j=0;j<2;j++){
        while(A[j].size()>=2){
            auto C = A[j].back();A[j].pop_back();
            auto D = A[j].back();A[j].pop_back();
            ans[C.S] = ans[D.S] = (C.F-D.F)/2+m-C.F;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i == n-1];
    }
}
int main(){
    read(T);
    while(T--){
        solve();
    }
    return 0;
}