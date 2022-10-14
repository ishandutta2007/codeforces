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

int n,m,k,dist[1200010],x[1200010],y[1200010],val[1200010],p[20],vis[1200010];
int main() {
    memset(dist,7,sizeof(dist));
    read(n,m,k);
    string s;
    int a=0,b =0;
    cin>>s;
    for(int i=k-1;i>=0;i--){
        a = a*2+s[i]-'0';
        p[i] = i;
    }
    cin>>s;
    int ans = 1e9;
    for(int i=k-1;i>=0;i--){
        b = b*2+s[i]-'0';
    }
    //cout<<a<<' '<<b<<endl;
    int ansl,ansr;
    for(int i=0;i<n;i++){
        read(x[i],y[i]);
        x[i]-=1;y[i]-=1;
        for(int j=0;j<k;j++)if((a>>j)&1)val[i]+=1<<p[j];
        //debug(i,val[i]);
        if(i-m+1>=0){
            //cout<<"insert "<<i-m+1<<' '<<val[i-m+1]<<endl;
            vector<pii> V;
            V.PB(MP(val[i-m+1],0));
            vis[val[i-m+1]] = i-m+1+1;
            dist[val[i-m+1]] = 0;
            for(int j=0;j<V.size();j++){
                int c1 = V[j].F,c2 = V[j].S;
                for(int k2=0;k2<k;k2++){
                    if(c2+1<dist[c1^(1<<k2)]){
                        dist[c1^(1<<k2)] = c2+1;
                        vis[c1^(1<<k2)] = i-m+1+1;
                        V.PB(MP(c1^(1<<k2),c2+1));
                    }
                }
            }
        }
        swap(p[x[i]],p[y[i]]);
        int nb = 0;
        for(int j=0;j<k;j++)if((b>>j)&1)nb+=1<<p[j];
        if(dist[nb]<ans){
            ansl = vis[nb];
            ansr = i+1;
        }
        ans = min(ans,dist[nb]);
    }
    cout<<k-ans<<endl;
    cout<<ansl<<' '<<ansr<<endl;
    return 0;
}