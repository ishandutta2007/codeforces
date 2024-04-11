#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,q,k,a[N],c[N],f[20][N];
long long v[20][N];
deque<int>s;
int main()
{
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		while(s.size()&&a[i]<=a[s.back()])
			s.pop_back();
		s.push_back(i);
		while(i+k<s.front())
			s.pop_front();
		c[i]=a[s.front()];
	}
	f[0][n+1]=n+1;
	for(int i=n;i>=1;i--)
	{
		f[0][i]=i+k;
		if(f[0][i]>n)
			f[0][i]=n+1;
		while(c[i]<c[f[0][i]])
			f[0][i]=f[0][f[0][i]];
		v[0][i]=1ll*(f[0][i]-i+k-1)/k*c[i];
	}
	for(int h=1;h<=19;h++)
	{
		for(int i=1;i<=n+1;i++)
		{
			f[h][i]=f[h-1][f[h-1][i]];
			v[h][i]=v[h-1][i]+v[h-1][f[h-1][i]];
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		long long z=a[x];
		for(int h=19;h>=0;h--)
		{
			if(f[h][x]<=y)
			{
				z+=v[h][x];
				x=f[h][x];
			}
		}
		z+=1ll*(y-x)/k*c[x];
		printf("%lld\n",z);
	}
	return 0;
}