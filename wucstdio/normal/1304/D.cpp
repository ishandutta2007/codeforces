#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[200005];
char s[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)p[i]=n-i+1;
		for(int i=1;i<n;)
		{
			int j=i;
			while(s[j]=='<')j++;
			reverse(p+i,p+j+1);
			i=j+1;
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		printf("\n");
		for(int i=1;i<=n;i++)p[i]=i;
		for(int i=1;i<n;)
		{
			int j=i;
			while(s[j]=='>')j++;
			reverse(p+i,p+j+1);
			i=j+1;
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}