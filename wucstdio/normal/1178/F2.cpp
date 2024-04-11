#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m,a[1005],minp[1005][1005],st[505],en[505];
ll f[1005][1005];
bool flag[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	memset(st,0x3f,sizeof(st));
	int top=0;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x!=a[top])
		{
			a[++top]=x;
			st[x]=min(st[x],top);
			en[x]=top;
		}
	}
	m=top;
	swap(n,m);
	memset(flag,1,sizeof(flag));
	for(int i=1;i<=n;i++)
	{
		minp[i][i]=i;
		f[i][i-1]=1;
		int minl=i,maxr=i;
		minl=min(minl,st[a[i]]);
		maxr=max(maxr,en[a[i]]);
		if(minl<i||maxr>i)flag[i][i]=0;
		else f[i][i]=1;
		for(int j=i+1;j<=n;j++)
		{
			minl=min(minl,st[a[j]]);
			maxr=max(maxr,en[a[j]]);
			if(minl<i||maxr>j)flag[i][j]=0;
			if(a[minp[i][j-1]]>a[j])minp[i][j]=j;
			else minp[i][j]=minp[i][j-1];
		}
	}
	f[n+1][n]=1;
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if(!flag[l][r])continue;
			int p1=st[a[minp[l][r]]],p2=en[a[minp[l][r]]];
			ll num1=0,num2=0;
			for(int i=l;i<=p1;i++)num1=(num1+f[l][i-1]*f[i][p1-1])%MOD;
			for(int i=p2;i<=r;i++)num2=(num2+f[p2+1][i]*f[i+1][r])%MOD;
			f[l][r]=num1*num2%MOD;
			int last=p1;
			for(int i=p1+1;i<=p2;i++)
			{
				if(a[i]==a[last])
				{
					f[l][r]=f[l][r]*f[last+1][i-1]%MOD;
					last=i;
				}
			}
		}
	}
	printf("%I64d\n",f[1][n]);
	return 0;
}