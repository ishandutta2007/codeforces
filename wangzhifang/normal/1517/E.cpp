#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 200000
int a[max_n+1];
ll b[max_n+1],c[max_n+1];
il void test(){//case 1: "P"*a+"C"*b, a,b>1; case 2: "P"*a+"C"*b+"PC"*c+"P"*d+"C"*e, a,b,c,d,e>=0, a,e<=1
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	ll ans=0;
	ll now=0;
	b[0]=c[0]=0;
	for(int i=1; i<=n; ++i)
		b[i]=now+=a[i];
	now=0;
	for(int i=1; i<=n; i+=2)
		c[i]=now+=a[i];
	now=0;
	for(int i=2; i<=n; i+=2)
		c[i]=now+=a[i];
	ll lim=(b[n]-1)>>1;
	for(int i=0; i<=n; ++i)//case 1
		if(b[n]-b[i]<=lim)
			++ans;
	for(int i=1; i<n; ++i)//case 2, a=c=e=0
		if(b[i]<=lim)
			++ans;
	for(int i=2; i<n; ++i)//case 2, a=1, c=e=0
		if(b[i]-a[1]<=lim)
			++ans;
	for(int i=2; i<n; ++i)//case 2, a=c=0, e=1
		if(a[n]+b[i-1]<=lim)
			++ans;
	for(int i=2; i<n-1; ++i)//case 2: a=e=1, c=0
		if(a[n]+b[i]-a[1]<=lim)
			++ans;
	for(int a=0; a<2; ++a)
		for(int e=0; e<2; ++e){
			ll now=e*::a[n];
			for(int i=2-a; i<n; ++i){
				now+=::a[i];
				int l=1,r=(n-1-e-i)/2;
				for(int mid; l<=r; now+c[i+2*(mid=(l+r)>>1)]-c[i]<=lim?(l=mid+1):(r=mid-1));
				ans+=r;
			}
		}
	printf("%lld\n",ans%998244353);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}