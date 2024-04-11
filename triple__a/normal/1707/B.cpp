//https://www.codechef.com/viewsolution/62157068

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=1e9+7;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=200007;
const int K=19;
mt19937 rng(1234);

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        int n;
        cin>>n;
        map<int,int> s;
        rep(i,n){
            int u;
            cin>>u;
            s[u]++;
        }
        rep(i,n-1){
            map<int,int> t;
            int prv=-1;
            for (auto [x,y]:s){
                if (prv==-1){
                    if (y>1) t[0]+=y-1;
                    prv=x; continue;
                } 
                t[x-prv]++; 
                if (y>1) t[0]+=y-1; 
                prv=x;
            }
            s=t;
        }
        assert(sz(s)==1);
        for (auto c:s) cout<<c.F<<"\n";
    }
    return 0;
}

/*
6
1234
1235
1244
1233
7133
8133
*/