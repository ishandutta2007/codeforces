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

int T,n,a[100010],dp[1010][1010][2][2] = {0};
int main() {
    /*dp[0][0][1][0] = 1;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int a=0;a<2;a++){
                for(int b=0;b<2;b++){
                    if(i && dp[i-1][j][b][a^1] == 0)dp[i][j][a][b] = 1;
                    if(j && dp[i][j-1][b][a] == 0)dp[i][j][a][b] = 1;
                }
            }
            if(i%2 == 1)cout<<dp[i][j][0][0];
        }
        if(i%2==1)cout<<endl;
    }*/
    read(T);
    while(T--){
        read(n);
        int xsum = 0;
        for(int i=0;i<n;i++){
            read(a[i]);
            xsum^=a[i];
        }
        if(xsum == 0)cout<<"DRAW\n";
        else{
            for(int i=29;i>=0;i--){
                if((xsum>>i)&1){
                    int cna = 0;
                    for(int j=0;j<n;j++)if((a[j]>>i)&1)cna+=1;
                    int cnb = n-cna;
                    if(cna%4 == 1 || (cna%4 == 3 && cnb%2 == 1)){
                        cout<<"WIN\n";
                    }else{
                        cout<<"LOSE\n";
                    }
                    break;
                }
            }
        }
        
    }
    return 0;
}