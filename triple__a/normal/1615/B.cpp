// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("trapv")
#include<bits/stdc++.h>

#define int long long
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=LLONG_MAX/4;
const int maxn=1000007;
const double EPS=1e-9;
int _;
int n,m,k;
int sum[maxn][20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>_;
    for (int i=0;i<20;++i){
        for (int j=1;j<=200000;++j){
            sum[j][i]=(j>>i&1)+sum[j-1][i];
        }
    }
    while (_--){
        int l,r;
        cin>>l>>r;
        l--;
        int mx=0;
        for (int i=0;i<20;++i){
            mx=max(sum[r][i]-sum[l][i],mx);
        }
        cout<<r-l-mx<<"\n";
    }
    return 0;
}

/*
5 3 
3 0 2 3 
3 3 0 1
4 0 1 3 4

2 0 3 1 4

1 0 3 4 
*/