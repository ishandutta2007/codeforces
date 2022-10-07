#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,p[200005],pos[200005],q[200005],maxx[200005];
char s[200005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)pos[q[i]]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		p[i]=pos[p[i]];
	}
	int now=0,top=0;
	for(int i=1;i<=n;i++)
	{
		maxx[i]=max(maxx[i-1],p[i]);
		if(maxx[i]==i)
		{
			now=min(now,25);
			while(top<i)s[q[++top]]='a'+now;
			now++;
		}
	}
	if(now<k)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)putchar(s[i]);
	putchar('\n');
	return 0;
}