#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],b[100005],t[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)t[b[i]]=i;
	int maxx=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,t[a[i]]);
		if(t[a[i]]!=maxx)ans++;
	}
	printf("%d\n",ans);
	return 0;
}