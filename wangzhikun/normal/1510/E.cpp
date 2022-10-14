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

int n;
double x,y;

map<pii,string> K[20][400];

void dfs(int c,int height,int sumx,int sumy,int siz,string CC){
    if(c == n/2){
        K[height][siz][MP(sumx,sumy)] = CC;
        return;
    }
    dfs(c+1,height+1,sumx+height*(c*2+1)*3+3*c+2,sumy+height*height*3+3*height+1,siz+height+height+1,CC+"(");
    if(height){
        dfs(c+1,height-1,sumx+height*(c*2+1)*3-3*c-2,sumy+(height-1)*(height-1)*3+3*(height-1)+1,siz+height+height-1,CC+")");
    }
}

int main() {
    read(n);
    cin>>x>>y;
    string c = "";
    dfs(0,0,0,0,0,c);
    for(int i=0;i<=n/2;i++){
        for(int j=1;j<400;j++){
            for(auto ct:K[i][j]){
                for(int k=1;k<400;k++){
                    double a = ((k+j)*x*3.0-ct.F.F),b = ((k+j)*y*3.0-ct.F.S);
                    //debug(a,b);
                    if(abs(a-(int)(a+0.5))<1e-4 && abs(b-(int)(b+0.5))<1e-4){
                        int ai = (int)(a+0.5),bi = (int)(b+0.5);
                        
                        ai = n*3*k-ai;
                        if(K[i][k].count(MP(ai,bi))){
                            if(abs((n*3*k-ai+ct.F.F)/(3.0*(k+j))-x)<1e-8 && abs((bi+ct.F.S)/(3.0*(k+j))-y)<1e-8){
                                cout<<ct.S;
                                for(int ii=0;ii<n/2;ii++){
                                    if(K[i][k][MP(ai,bi)][n/2-1-ii] == '(')cout<<')';
                                    else cout<<'(';
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"WF"<<endl;
    return 0;
}