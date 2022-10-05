#include <bits/stdc++.h>
using namespace std;
long long ans=1e18,faca[1000005],facb[1000005],facc[1000005],a,b,c,cta,ctb,ctc; 
int main()
{
 	scanf("%I64d%I64d",&a,&b);
 	c=a+b;
 	int aa=ceil(sqrt(a)),bb=ceil(sqrt(b)),cc=ceil(sqrt(c));
 	for(int i=1;i<=aa;i++)
 	{
 		if(!(a%i))
 		{
 			faca[++cta]=i;
 			if(i!=a/i) faca[++cta]=a/i;
 		}
 	}
 	for(int i=1;i<=bb;i++)
 	{
 		if(!(b%i))
 		{
 			facb[++ctb]=i;
 			if(i!=b/i) facb[++ctb]=b/i;
 		}
 	}
 	for(int i=1;i<=cc;i++)
 	{
 		if(!(c%i))
 		{
 			facc[++ctc]=i;
 			if(i!=c/i) facc[++ctc]=c/i;
 		}
 	}
 	sort(faca+1,faca+1+cta);
 	sort(facb+1,facb+1+ctb);
 	sort(facc+1,facc+1+ctc);
 	for(int i=1;i<=ctc;i++)
 	{
 		long long x=facc[i],y=c/facc[i];
 		if(x<y) swap(x,y);
 		long long z=upper_bound(faca+1,faca+1+cta,x)-faca-1;
 		if(z<=cta&&z>=0&&y>=a/faca[z])
 			ans=min(ans,2*(x+y));
 		z=upper_bound(facb+1,facb+1+ctb,x)-facb-1;
 		if(z<=ctb&&z>=0&&y>=b/facb[z])
 			ans=min(ans,2*(x+y));
 	}
 	printf("%I64d",ans);
 	return 0;
}