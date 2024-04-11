#include<bits/stdc++.h>
using namespace std;
const int N=100005,P=17;
int can[1<<P],d[P][P],a[N],c[P],r[N],f[1<<P],las[P],n,p;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>p>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i]-'a';
		r[a[i]]++;
	}
	for(int i=0;i<p;i++)
		for(int j=0;j<p;j++)
			cin>>d[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(!las[j])
				continue;
			int mask=c[j];
			if(mask&(1<<a[i]))
				continue;
			if(d[a[i]][j])
				continue;
			can[mask]=1;
			f[mask]--;
			f[mask|(1<<a[i])]++;
			f[mask|(1<<j)]++;
			f[mask|(1<<a[i])|(1<<j)]--;
		}
		las[a[i]]=i;
		for(int j=0;j<p;j++)
			c[j]|=1<<a[i];
		c[a[i]]=0;
	}
	int ans=n;
	for(int i=1;i<(1<<p);i++)
	{
		int cb=0;
		for(int m=i;m;m=(m-1)&i)
			cb+=f[m];
		if(cb<0)
			can[i]=1;
		if(can[i])
			continue;
		int flag=0;
		for(int j=0;j<p;j++)
		{
			if(i&(1<<j))
			{
				if(can[i^(1<<j)]==0)
				{
					flag=1;
					break;
				}
			}
		}
		if(!flag)
			can[i]=1;
		if(!can[i])
		{
			int sum=n;
			for(int j=0;j<17;j++)
				if(i&(1<<j))
					sum-=r[j];
			ans=min(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}