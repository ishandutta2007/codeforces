#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,sa[150005],sa2[150005],rnk[150005];
ll T,t[150005],p[150005],L[150005],R[150005];
bool cmp(int a,int b)
{
	return p[a]*t[b]>p[b]*t[a]||(p[a]*t[b]==p[b]*t[a]&&p[b]>p[a]);
}
bool cmp2(int a,int b)
{
	return p[a]<p[b]||(p[a]==p[b]&&rnk[a]>rnk[b]);
}
bool check(double c)
{
	double maxx=0;
	for(int i=1;i<=n;i++)
	{
		double v1=(double)p[sa2[i]]*(1.0-c*(double)L[sa2[i]]/(double)T);
		double v2=(double)p[sa2[i]]*(1.0-c*(double)R[sa2[i]]/(double)T);
		if(p[sa2[i]]!=p[sa2[i-1]]&&v2<maxx)return 0;
		maxx=max(maxx,v1);
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++)sa[i]=i,T+=t[i],sa2[i]=i;
	sort(sa+1,sa+n+1,cmp);
	double l=0,r=1;
	ll s=0;
	for(int i=1;i<=n;)
	{
		int j=i;
		ll tt=0;
		while(p[sa[i]]*t[sa[j]]==p[sa[j]]*t[sa[i]]&&j<=n)tt+=t[sa[j]],j++;
		j--;
		for(int k=i;k<=j;k++)
		{
			L[sa[k]]=s+t[sa[k]];
			R[sa[k]]=s+tt;
			if(k==j||p[sa[k+1]]==p[sa[k]])continue;
			r=min(r,(double)T*(double)(p[sa[k]]-p[sa[k+1]])/((double)s*(double)p[sa[k]]+(double)t[sa[k]]*(double)p[sa[k]]-(double)s*(double)p[sa[k+1]]-(double)tt*(double)p[sa[k+1]]));
		}
		i=j+1;
		s+=tt;
	}
	for(int i=1;i<=n;i++)rnk[sa[i]]=i;
	sort(sa2+1,sa2+n+1,cmp2);
	for(int i=1;i<=100;i++)
	{
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.12lf\n",(l+r)/2);
	return 0;
}