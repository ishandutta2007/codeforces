#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1005],b[1005],sa[1005];
bool check()
{
	for(int i=1;i<=n;i++)
	  if(a[i]!=i)return 0;
	return 1;
}
bool cmp(int i,int j)
{
	return a[i]<a[j]||(a[i]==a[j]&&i<j);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sa[i]=i;
	sort(sa+1,sa+n+1,cmp);
	for(int i=1;i<=n;i++)a[sa[i]]=i;
	for(int i=1;i<=n;i++)b[a[i]]=i;
	int ans=0;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    ans+=(a[i]>a[j]);
	printf("%d\n",ans);
	while(!check())
	{
		for(int i=1;i<n;i++)
		{
			if(b[i]>b[i+1])
			{
				printf("%d %d\n",b[i+1],b[i]);
				swap(a[b[i+1]],a[b[i]]);
				swap(b[i],b[i+1]);
				i++;
			}
		}
	}
	return 0;
}