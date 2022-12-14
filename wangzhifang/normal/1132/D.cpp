#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max_n 200000
ll a[max_n+1],b[max_n+1],p[max_n+1];
int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}
int main(){
	ll n,k;
	scanf("%lld%lld",&n,&k);k--;
	for(int i=1; i<=n; ++i)
		scanf("%lld",&a[i]);
	for(int i=1; i<=n; ++i)
		scanf("%lld",&b[i]);
	ll l=0,r=3e12,mid,x,v,y;
	while(l<r){
		mid=(l+r)/2;
		for(int i=1; i<=k; ++i)
			p[i]=i;
		for(int i=1; i<=n; ++i){
			x=a[i];
			while(b[i]*k>x){
				v=x/b[i]+1;
				y=find(v);
				if(!y)
					goto lab;
				p[y]=y-1;
				x+=mid;
			}	
		}
		r=mid;
		continue;
		lab:
		l=mid+1;
	}
	if(l>=3e12)
		puts("-1");
	else
		printf("%lld\n",l);
	return 0;
}