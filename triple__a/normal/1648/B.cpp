// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
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
 
int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};
const int mod=998244353;
const int INF=LLONG_MAX/100;
const double EPS=1e-9;
const int N=1000007;
const int K=63;
 
mt19937 rng(1234);

int n,m,k;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>m;
        vi a(n,0), c(m+1,0), ok(m+7,0);
        rep(i,n) cin>>a[i], c[a[i]]++, ok[a[i]]=1;
        for (int i=1;i<=m;++i) c[i]+=c[i-1];
        if (!ok[1]){
            cout<<"No\n";
            continue;
        }
        bool okk=1;
        for (int i=2;i<=m;++i){
            if (!ok[i]) continue;
            for (int j=2;i*j<=m;++j){
                if (!ok[j]&&c[min(i*(j+1)-1,m)]>c[i*j-1]) okk=0;
            }
        }
        if (okk) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
/*
6 6
1 2
1 3
2 4
2 5
4 6
5 6
*/