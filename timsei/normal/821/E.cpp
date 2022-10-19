using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long

struct matrix{
	ll it[21][21];
}mu;
const ll mod=1e9+7;
ll n,k;
ll a[201],b[201],c[201];
ll ans[21];
ll bef[21];
matrix st[65];
void prll(matrix xx)
{
	for(ll i=0;i<=20;i++)
	{
		for(ll j=0;j<=20;j++)
		{
			cout<<xx.it[i][j]<<" ";
		}
		puts("");
	}
}
matrix operator * (matrix a,matrix b)
{
	matrix c;
	for(ll i=0;i<=20;i++)
	{
		for(ll j=0;j<=20;j++)
		{
			c.it[i][j]=0;
			for(ll k=0;k<=20;k++)
			{
				c.it[i][j]=(c.it[i][j]+a.it[i][k]*b.it[k][j])%mod;
			}
		}
	}
	return c;
}
matrix pow(ll x)
{
	matrix hh;
	bool flag=0;
	st[1]=mu;
	ll cnt=0;
	for(ll i=2;i<=64;i++)st[i]=st[i-1]*st[i-1];
	while(x)
	{
		cnt++;
		if(x%2){if(!flag) hh=st[cnt];else hh=hh*st[cnt];flag=1;}
		x>>=1;
	}
	return hh;
}
ll tot;
int main()
{
	cin>>n>>k;
	ans[0]=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]>=k)
		{
			b[i]=k;
			tot=i;break;
		}
	}
	n=tot;
	for(ll i=1;i<=n;i++)
	{
		memset(mu.it,0,sizeof(mu.it));
		for(ll j=0;j<=c[i];j++)
		{
			if(j==0){mu.it[j][0]=mu.it[j][1]=1;}
			else
			if(j==c[i])
			{
				mu.it[j][c[i]]=mu.it[j][c[i]-1]=1;
			}
			else
			mu.it[j][j-1]=mu.it[j][j]=mu.it[j][j+1]=1;
		}
		matrix hh=pow(b[i]-a[i]);
		for(ll j=0;j<=20;j++)
		{
			bef[j]=0;
			for(ll k=0;k<=20;k++)
			{	
				bef[j]=(bef[j]+ans[k]*hh.it[k][j])%mod;
			}
		}
		for(ll j=0;j<=20;j++) ans[j]=bef[j];
		for(ll j=c[i]+1;j<=20;j++) ans[j]=0;
	}
	cout<<ans[0]<<endl;
}