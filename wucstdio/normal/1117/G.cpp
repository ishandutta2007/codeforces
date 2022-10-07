#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,q,a[1000005],maxp[26][1000005],lg2[1000005],st[1000005],top;
int pre[1000005],nxt[1000005],l[1000005],r[1000005];
ll dis1[1000005],dis2[1000005],f1[1000005],f2[1000005],s1[1000005],s2[1000005];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxp[0][i]=i;
	}
	for(int i=2;i<=n;i++)
	  lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=lg2[n];i++)
	  for(int j=1;j<=n;j++)
	    maxp[i][j]=a[maxp[i-1][j]]>a[maxp[i-1][j+(1<<(i-1))]]?maxp[i-1][j]:maxp[i-1][j+(1<<(i-1))];
	for(int i=1;i<=n;i++)
	{
		while(top&&a[st[top]]<a[i])top--;
		pre[i]=st[top];
		st[++top]=i;
		f1[i]=f1[pre[i]]+1;
		dis1[i]=i-pre[i];
		s1[i]=s1[i-1]+f1[i]+dis1[i];
	}
	top=0;
	st[0]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[st[top]]<a[i])top--;
		nxt[i]=st[top];
		st[++top]=i;
		f2[i]=f2[nxt[i]]+1;
		dis2[i]=nxt[i]-i;
		s2[i]=s2[i+1]+f2[i]+dis2[i];
	}
	for(int i=1;i<=q;i++)scanf("%d",&l[i]);
	for(int i=1;i<=q;i++)scanf("%d",&r[i]);
	for(int i=1;i<=q;i++)
	{
		int d=lg2[r[i]-l[i]+1];
		int p=a[maxp[d][l[i]]]>a[maxp[d][r[i]-(1<<d)+1]]?maxp[d][l[i]]:maxp[d][r[i]-(1<<d)+1];
		printf("%lld ",1+s1[r[i]]-s1[p]-f1[p]*(r[i]-p)+s2[l[i]]-s2[p]-f2[p]*(p-l[i]));
	}
	printf("\n");
	return 0;
}