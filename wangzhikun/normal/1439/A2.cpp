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

int T,n,m;

char cmp[110][110];

vector<pii> ans;

void op(int x,int y){
    if(cmp[x][y] == '1')cmp[x][y] = '0';
    else cmp[x][y] = '1';
    ans.PB(MP(x,y));
}

int main() {
    read(T);
    while(T--){
        read(n,m);
        ans.clear();
        for(int i=1;i<=n;i++)cin>>(cmp[i]+1);
        
        if(n%2 == 1 && m%2 == 1){
            if(cmp[n][m] == '1'){
                op(n,m);
                op(n,m-1);
                op(n-1,m-1);
            }
        }
        if(n%2 == 1){
            for(int j=1;j+1<=m;j+=2){
                if(cmp[n][j] == '1' && cmp[n][j+1] == '0'){
                    op(n-1,j);
                    op(n-1,j+1);
                    op(n,j);
                }else if(cmp[n][j] == '0' && cmp[n][j+1] == '1'){
                    op(n-1,j);
                    op(n-1,j+1);
                    op(n,j+1);
                }else if(cmp[n][j] == '1' && cmp[n][j+1] == '1'){
                    op(n-1,j);
                    op(n,j);
                    op(n,j+1);
                }
            }
        }
        if(m%2 == 1){
            for(int j=1;j+1<=n;j+=2){
                if(cmp[j][m] == '1' && cmp[j+1][m] == '0'){
                    op(j,m);
                    op(j,m-1);
                    op(j+1,m-1);
                }else if(cmp[j][m] == '0' && cmp[j+1][m] == '1'){
                    op(j+1,m);
                    op(j,m-1);
                    op(j+1,m-1);
                }else if(cmp[j][m] == '1' && cmp[j+1][m] == '1'){
                    op(j+1,m);
                    op(j,m);
                    op(j,m-1);
                }
            }
        }
        for(int i=1;i+1<=n;i+=2){
            for(int j=1;j+1<=m;j+=2){
                int cnt = 0;
                for(int i1=i;i1<=i+1;i1++){
                    for(int j1=j;j1<=j+1;j1++){
                        if(cmp[i1][j1] == '1')cnt+=1;
                    }
                }
                if(cnt == 0)continue;
                if(cnt == 3){
                    for(int i1=i;i1<=i+1;i1++){
                        for(int j1=j;j1<=j+1;j1++){
                            if(cmp[i1][j1] == '1')op(i1,j1);
                        }
                    }
                    continue;
                }
                if(cnt == 2 || cnt == 4){
                    op(i,j);
                    op(i,j+1);
                    op(i+1,j);
                    cnt = 0;
                    for(int i1=i;i1<=i+1;i1++){
                        for(int j1=j;j1<=j+1;j1++){
                            if(cmp[i1][j1] == '1')cnt+=1;
                        }
                    }
                    if(cnt == 3){
                        for(int i1=i;i1<=i+1;i1++){
                            for(int j1=j;j1<=j+1;j1++){
                                if(cmp[i1][j1] == '1')op(i1,j1);
                            }
                        }
                        continue;
                    }
                }
                //cnt = 1;
                if(cmp[i][j] == '1'){
                    op(i,j);op(i,j+1);op(i+1,j);
                    op(i,j);op(i,j+1);op(i+1,j+1);
                }else if (cmp[i][j+1] == '1'){
                    op(i,j);op(i,j+1);op(i+1,j+1);
                    op(i,j);op(i,j+1);op(i+1,j);
                }else if (cmp[i+1][j] == '1'){
                    op(i,j);op(i+1,j+1);op(i+1,j);
                    op(i,j);op(i,j+1);op(i+1,j);
                }else{
                    op(i+1,j+1);op(i,j+1);op(i+1,j);
                    op(i,j);op(i,j+1);op(i+1,j+1);
                }
                for(int i1=i;i1<=i+1;i1++){
                    for(int j1=j;j1<=j+1;j1++){
                        if(cmp[i1][j1] == '1')op(i1,j1);
                    }
                }
            }
        }
        cout<<ans.size()/3<<endl;
        for(int i=0;i<ans.size();i+=3){
            cout<<ans[i].F<<' '<<ans[i].S<<' '<<ans[i+1].F<<' '<<ans[i+1].S<<' '<<ans[i+2].F<<' '<<ans[i+2].S<<'\n';
        }
        ans.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)assert(cmp[i][j] == '0');
        }
    }
    return 0;
}