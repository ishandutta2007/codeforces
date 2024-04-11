#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],b[200005],pos[200005],pre[200005],nxt[200005];
void del(int i)
{
	pre[nxt[i]]=pre[i];
	nxt[pre[i]]=nxt[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		int c=getchar();
		while(c!='+'&&c!='-')c=getchar();
		if(c=='-')scanf("%d",&a[i]);
		if(a[i])pos[a[i]]=i;
		pre[i]=i-1,nxt[i]=i+1;
	}
	nxt[0]=1,pre[2*n+1]=2*n;
	for(int i=1;i<=n;i++)
	{
		int p=pos[i];
		if(a[pre[p]]||!pre[p])
		{
			printf("NO\n");
			return 0;
		}
		b[pre[p]]=i;
		del(pre[p]);
		del(p);
	}
	printf("YES\n");
	for(int i=1;i<=2*n;i++)
		if(b[i])printf("%d ",b[i]);
	printf("\n");
	return 0;
}