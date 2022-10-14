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

int n,m,visa[1010],visb[1010];
char mp[1010][1010];
void dfs(int a,int b){
    if(a<0 || b<0)return;
    if(a>=n || b>=m)return;
    if(mp[a][b]!='#')return;
    mp[a][b] = 'X';
    dfs(a-1,b);
    dfs(a+1,b);
    dfs(a,b-1);
    dfs(a,b+1);
}
int main() {
    read(n,m);
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    int cnta = 0,cntb = 0,ka  = 0,kb = 0;
    for(int i=0;i<n;i++){
        int state = 0;
        int k = 0;
        for(int j=0;j<m;j++){
            if(mp[i][j] == '#'){
                k = 1;
                cnta+=1-visa[i];
                visa[i] = 1;
                cntb+=1-visb[j];
                visb[j] = 1;
            }
            if(mp[i][j] == '#' && state == 0) state = 1;
            if(mp[i][j] == '.' && state == 1) state = 2;
            if(mp[i][j] == '#' && state == 2){
                cout<<-1<<endl;
                return 0;
            }
        }
        ka+=1-k;
    }
    for(int i=0;i<m;i++){
        int state = 0;
        int k = 0;
        for(int j=0;j<n;j++){
            if(mp[j][i] == '#'){
                k = 1;
            }
            if(mp[j][i] == '#' && state == 0) state = 1;
            if(mp[j][i] == '.' && state == 1) state = 2;
            if(mp[j][i] == '#' && state == 2){
                cout<<-1<<endl;
                return 0;
            }
        }
        kb+=1-k;
    }
    if(cnta!=n && !kb){
        cout<<-1<<endl;
        return 0;
    }
    if(cntb!=m && !ka){
        cout<<-1<<endl;
        return 0;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j] == '#'){
                cnt+=1;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}