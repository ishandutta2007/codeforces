#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 998244353;
const int N = 1005;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,a[N][N];

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	int cnt = 0;
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=n;j+=4){
			rep(k,0,3) a[i][j+k] = cnt++;
			rep(k,0,3) a[i+1][j+k] = cnt++;
		}
	}
	rep(i,1,n)rep(j,1,n)printf("%d%c",a[i][j],j==n?'\n':' ');
	return 0;
}