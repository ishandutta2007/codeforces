#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9+1;
const int N = 2e5+5;
mt19937 rng(time(0));

int T, n, mi, ma;
LL k;
int a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		ma = -INF, mi = INF;
		scanf("%d%lld",&n,&k);
		rep(i,1,n) scanf("%d",a+i), mi = min(mi, a[i]), ma = max(ma, a[i]);
		if(k%2ll==0){
			rep(i,1,n) a[i] = a[i] - mi;
		}else{
			rep(i,1,n) a[i] = ma - a[i];
		}
		rep(i,1,n) printf("%d ",a[i]);
		printf("\n");
	}
	
	return 0;
}