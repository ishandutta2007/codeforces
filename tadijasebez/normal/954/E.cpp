#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=200050;
int id[N],t[N],a[N];
bool comp(int a, int b){ return t[a]<t[b];}
int main()
{
	int n,T,i;
	scanf("%i %i",&n,&T);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&t[i]);
	for(i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,comp);
	ll p=0,q=0;
	for(i=1;i<=n;i++)
	{
		p+=(ll)a[i]*t[i];
		q+=a[i];
	}
	if(p<q*T)
	{
		reverse(id+1,id+1+n);
		p=q=0;
		for(i=1;i<=n;i++)
		{
			p+=(ll)a[id[i]]*t[id[i]];
			q+=a[id[i]];
			if(p<q*T) break;
		}
		if(i>n) return printf("%lld\n",q),0;
		p-=(ll)a[id[i]]*t[id[i]];
		q-=a[id[i]];
		if(T==t[id[i]]) printf("???\n");
		double x=(double)(p-q*T)/(T-t[id[i]]);
		x+=q;
		printf("%.12llf\n",x);
	}
	else
	{
		p=q=0;
		for(i=1;i<=n;i++)
		{
			p+=(ll)a[id[i]]*t[id[i]];
			q+=a[id[i]];
			if(p>q*T) break;
		}
		if(i>n) return printf("%lld\n",q),0;
		p-=(ll)a[id[i]]*t[id[i]];
		q-=a[id[i]];
		if(T==t[id[i]]) printf("???\n");
		double x=(double)(p-q*T)/(T-t[id[i]]);
		x+=q;
		printf("%.12llf\n",x);
	}
	return 0;
}