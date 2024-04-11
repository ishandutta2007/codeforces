#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 300010;

LL n,a[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+1+n);
	LL ans=0;
	rep(i,1,n/2){
		ans+=(a[i]+a[n+1-i])*(a[i]+a[n+1-i]);
	}
	cout<<ans<<endl;
	return 0;
}