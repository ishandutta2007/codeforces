#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,a[N],p[N],x,m,r[N];
bitset<N>f[65];
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x^=a[i];
	}
	for(int k=0;k<2;k++)
	{
		for(int i=62;i>=0;i--)
		{
			if(((x>>i)&1)!=k)
				continue;
			m++;
			for(int j=1;j<=n;j++)
				if((a[j]>>i)&1)
					f[m][j]=1;
			f[m][n+1]=k^1;
			for(int j=1;j<m;j++)
				if(f[m][p[j]])
					f[m]^=f[j];
			p[m]=0;
			for(int j=1;j<=n;j++)
			{
				if(f[m][j])
				{
					p[m]=j;
					break;
				}
			}
			if(!p[m])
			{
				m--;
				continue;
			}
			for(int j=1;j<m;j++)
				if(f[j][p[m]])
					f[j]^=f[m];
		}
	}
	for(int i=0;i<=62;i++)
		r[p[i]]=f[i][n+1];
	for(int i=1;i<=n;i++)
		cout<<2-r[i]<<' ';
	return 0;
}