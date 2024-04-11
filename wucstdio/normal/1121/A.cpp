#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int maxx[1005],n,m,k,p[1005],a[1005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	  scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx[a[i]]=max(maxx[a[i]],p[i]);
	}
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		if(p[x]!=maxx[a[x]])ans++;
	}
	printf("%d\n",ans);
	return 0;
}