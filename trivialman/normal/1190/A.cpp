#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 100010;

LL n,m,k,a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%lld%lld%lld",&n,&m,&k);
	rep(i,1,m)scanf("%lld",a+i);
	LL r = 0;
	LL i,j,ans=0;
	for(i=1;i<=m;i=j){
		for(j=i;j<=m&&(a[j]-r-1)/k==(a[i]-r-1)/k;++j);
		++ans;
		r = (r+j-i)%k;
	}
	printf("%d\n",ans);
	return 0;
}