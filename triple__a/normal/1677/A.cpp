// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
#define double long double
// #define i128 long long
// #define double long double
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
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=1e9+7;
const double EPS=1e-6;
const double pi=acos(-1);
const int INF=1e18;
const int N=5007;
mt19937 rng(1235);

int n;
int a[N],sum[N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
	int _;
	cin>>_;
	while (_--){
		cin>>n;
		rep1(i,n) rep1(j,n) sum[i][j]=0; 
		rep1(i,n) cin>>a[i], a[i]=n+1-a[i];
		rep1(i,n) {
			rep1(j,a[i]) sum[i][j]=1;
		} 
		rep1(j,n){
			rep1(i,n) sum[i][j]+=sum[i-1][j];
		}
		int ans=0;
		for (int i=1;i<=n;++i){
			for (int j=i+1;j<=n;++j){
				ans+=sum[i-1][a[j]]*(sum[n][a[i]]-sum[j][a[i]]);
				// cerr<<i<<" "<<j<<" "<<sum[i-1][a[j]]<<" "<<sum[n][a[i]]-sum[j][a[i]]<<endl;
			}
		}
		cout<<ans<<"\n";
	}
    return 0; 
}
/*
7 9 3 4
1 2 1
2 3 1
3 1 2
1 4 3
5 6 2
6 7 1
6 7 3
7 7 2
5 5 1
6 7
1 4
2 4
2 5
*/