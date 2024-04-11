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
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

int n,a[200020],p1[400040],p2[400040],cnt[200020];

int *vis = p1+200020,*val = p2+200020;

vector<int> ocur[200020];

int main() {
    read(n);
    int mx = 0,mi = 0;
    for(int i=1;i<=n;i++){
        read(a[i]);
        cnt[a[i]]+=1;
        ocur[a[i]].PB(i);
        if(cnt[a[i]]>mx){
            mx = cnt[a[i]];
            mi = a[i];
        }
    }
    
    set<int> S;
    for(auto ct:ocur[mi])S.insert(ct);
    
    int ans = 0,viskey = 1;
    for(int j=1;j<=n;j++){
        if(j == mi) continue;
        
        set<int> scope;
        
        for(auto ct:ocur[j]){
            auto it = S.lower_bound(ct);
            if(it != S.end()){
                scope.insert(*it);
                S.erase(*it);
            }
            it = S.lower_bound(ct);
            if(it != S.end()){
                scope.insert(*it);
                S.erase(*it);
            }
            it = S.lower_bound(ct);
            if(it != S.begin()){
                it--;
                scope.insert(*it);
                S.erase(*it);
            }
            it = S.lower_bound(ct);
            if(it != S.begin()){
                it--;
                scope.insert(*it);
                S.erase(*it);
            }
        }
        vector<int> bins;
        for(auto ct:scope)bins.PB(ct);
        for(auto ct:ocur[j])scope.insert(ct);
        
        int rb = -1;
        int cv = 0;
        for(auto ct:scope){
            if(ct>=rb){
                cv = 0;
                viskey+=1;
            }
            if(vis[cv]!=viskey){
                vis[cv] = viskey;
                val[cv] = ct;
            }
            if(a[ct] == j)  cv-=1;
            if(a[ct] == mi) cv+=1;
            if(S.lower_bound(ct) !=S.end()){
                rb = *S.lower_bound(ct);
            }else{
                rb = 1e9;
            }
            if(vis[cv] == viskey){
                int clid = val[cv];
                auto a = scope.lower_bound(clid);
                int cl,cr;
                if(a == scope.begin())cl = 0;
                else{
                    a--;
                    cl = *a;
                }
                auto b = scope.lower_bound(ct);
                b++;
                if(b == scope.end()){
                    cr = n+1;
                }else{
                    cr = *b;
                }
                ans = max(ans,cr-cl-1);
            }
        }
        for(auto ct:bins)S.insert(ct);
    }
    cout<<ans<<endl;
    return 0;
}