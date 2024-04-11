#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,h,w,edgenum,p[100005],pa[100005];
char s[105][105];
ll MOD;
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int add(int i1,int j1,int i2,int j2)
{
	int u=(i1-1)*w+j1;
	int v=(i2-1)*w+j2;
	if(find(u)==find(v))return 0;
	pa[find(u)]=find(v);
	return 1;
}
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
struct Matrix
{
	ll a[205][205];
	ll*operator[](int i){return a[i];}
	ll det()
	{
		ll ans=1;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    a[i][j]=(a[i][j]%MOD+MOD)%MOD;
		for(int i=1;i<n;i++)
		{
			int now=i;
			for(int j=i;j<n;j++)
			{
				if(a[j][i])
				{
					now=j;
					break;
				}
			}
			if(i!=now)
			{
				for(int j=i;j<n;j++)
				  swap(a[i][j],a[now][j]);
				ans*=-1;
			}
			ans=ans*a[i][i]%MOD;
			ll t=quick_pow(a[i][i],MOD-2);
			for(int j=i;j<n;j++)a[i][j]=a[i][j]*t%MOD;
			for(int j=i+1;j<n;j++)
			{
				ll t=a[j][i];
				for(int k=i;k<n;k++)
				  a[j][k]=(a[j][k]-a[i][k]*t%MOD+MOD)%MOD;
			}
		}
		if(ans<0)ans+=MOD;
		return ans;
	}
}A;
int main()
{
	scanf("%d%d%lld",&h,&w,&MOD);
	for(int i=1;i<=h;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=(h+1)*(w+1);i++)pa[i]=i;
	ll ans=0;
	bool flag=1;
	for(int i=1;i<=h;i++)
	for(int j=(i-1)%2+1;j<=w;j+=2)
	{
		if(s[i][j]=='\\')
		{
			flag&=add(i,(j+1)/2,i+1,j/2+1);
		}
	}
	for(int i=1;i<=h;i++)
	for(int j=i%2+1;j<=w;j+=2)
	{
		if(s[i][j]=='/')
		{
			flag&=add(i,j/2+1,i+1,(j+1)/2);
		}
	}
	for(int i=2;i<=(w+2)/2;i++)flag&=add(1,1,1,i);
	for(int i=1;i<=(h&1?(w+1)/2:(w+2)/2);i++)flag&=add(1,1,h+1,i);
	for(int i=3;i<=h;i+=2)flag&=add(1,1,i,1);
	for(int i=(w&1?2:3);i<h+1;i+=2)flag&=add(1,1,i,w/2+1);
	if(flag)
	{
		for(int i=1;i<=h+1;i++)
		  for(int j=1;j<=(i&1?(w+2)/2:(w+1)/2);j++)
			if(!p[find((i-1)*w+j)])
			  p[find((i-1)*w+j)]=++n;
		for(int i=1;i<=h;i++)
		for(int j=(i-1)%2+1;j<=w;j+=2)
		{
			if(s[i][j]=='*')
			{
				int u=(i-1)*w+(j+1)/2;
				int v=i*w+j/2+1;
				u=p[find(u)];
				v=p[find(v)];
				A[u][u]++;
				A[v][v]++;
				A[u][v]--;
				A[v][u]--;
			}
		}
		for(int i=1;i<=h;i++)
		for(int j=i%2+1;j<=w;j+=2)
		{
			if(s[i][j]=='*')
			{
				int u=(i-1)*w+j/2+1;
				int v=i*w+(j+1)/2;
				u=p[find(u)];
				v=p[find(v)];
				A[u][u]++;
				A[v][v]++;
				A[u][v]--;
				A[v][u]--;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			  printf("%lld ",A[i][j]);
//			printf("\n");
//		}
		ans+=A.det();
	}
	memset(p,0,sizeof(p));
	edgenum=n=0;
	memset(A.a,0,sizeof(A.a));
	for(int i=1;i<=(h+1)*(w+1);i++)pa[i]=i;
	flag=1;
	for(int i=1;i<=h;i++)
	for(int j=(i-1)%2+1;j<=w;j+=2)
	{
		if(s[i][j]=='/')
		{
			flag&=add(i,j/2+1,i+1,(j+1)/2);
		}
	}
	for(int i=1;i<=h;i++)
	for(int j=i%2+1;j<=w;j+=2)
	{
		if(s[i][j]=='\\')
		{
			flag&=add(i,(j+1)/2,i+1,j/2+1);
		}
	}
	for(int i=2;i<=(w+1)/2;i++)flag&=add(1,1,1,i);
	for(int i=1;i<=(h&1?(w+2)/2:(w+1)/2);i++)flag&=add(1,1,h+1,i);
	for(int i=2;i<=h;i+=2)flag&=add(1,1,i,1);
	for(int i=(w&1?3:2);i<h+1;i+=2)flag&=add(1,1,i,w/2+1);
	if(flag)
	{
		for(int i=1;i<=h+1;i++)
		  for(int j=1;j<=(i&1?(w+1)/2:(w+2)/2);j++)
			if(!p[find((i-1)*w+j)])
			  p[find((i-1)*w+j)]=++n;
		for(int i=1;i<=h;i++)
		for(int j=(i-1)%2+1;j<=w;j+=2)
		{
			if(s[i][j]=='*')
			{
				int u=(i-1)*w+(j/2+1);
				int v=i*w+(j+1)/2;
				u=p[find(u)];
				v=p[find(v)];
				A[u][u]++;
				A[v][v]++;
				A[u][v]--;
				A[v][u]--;
			}
		}
		for(int i=1;i<=h;i++)
		for(int j=i%2+1;j<=w;j+=2)
		{
			if(s[i][j]=='*')
			{
				int u=(i-1)*w+(j+1)/2;
				int v=i*w+j/2+1;
				u=p[find(u)];
				v=p[find(v)];
				A[u][u]++;
				A[v][v]++;
				A[u][v]--;
				A[v][u]--;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			  printf("%lld ",A[i][j]);
//			printf("\n");
//		}
		ans+=A.det();
	}
	if(ans>=MOD)ans-=MOD;
	printf("%lld\n",ans);
	return 0;
}