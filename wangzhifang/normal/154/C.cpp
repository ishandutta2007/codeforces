#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define max_n 1000000
ll a[max_n<<1],h[max_n<<1];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	a[n]=h[0]=1;
	for(int i=1; i<n; ++i)
		a[n+i]=h[i]=h[i-1]*3;
	for(int r,l; m; --m){
		scanf("%d%d",&r,&l);
		--l,--r;
		a[l]+=h[r],a[r]+=h[l];
		a[l+n]+=h[r],a[r+n]+=h[l];
	}
	sort(a,a+n*2);
	ll ans=0;
	for(int l=0,r=1; r<n*2; ++r)
		if(a[r]!=a[r-1])
			l=r;
		else
			ans+=r-l;
	printf("%lld\n",ans);
	return 0;
}