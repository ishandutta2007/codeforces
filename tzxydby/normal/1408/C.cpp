#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T;
long long n,l;
double t1[N],t2[N],a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&l);
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		a[n+1]=l;
		for(int i=1;i<=n+1;i++)
			t1[i]=t1[i-1]+1.0*(a[i]-a[i-1])/i;
		t2[n+1]=0;
		for(int i=n;i>=1;i--)
			t2[i]=t2[i+1]+1.0*(a[i+1]-a[i])/(n-i+1);
		for(int i=1;i<=n+1;i++)
		{
			if(t1[i]==t2[i])
			{
				printf("%.9lf\n",t1[i]);
				break;
			}
			if(t1[i]>t2[i])
			{
				double x=t1[i-1],ans=t2[i],dis=a[i]-a[i-1];
				dis-=(ans-x)*i;
				ans+=dis/(n+2);
				printf("%.9lf\n",ans);
				break;
			}
		}
	}	
	return 0;
}