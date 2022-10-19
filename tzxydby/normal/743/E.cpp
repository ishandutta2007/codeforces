#include<bits/stdc++.h>
using namespace std;
const int N=1005,INF=0x3f3f3f3f;
int n,l,r,ans;
int a[N],b[N];
int f[N][1<<8];
vector<int>v[N];
int check(int x)
{
	memset(b,0,sizeof(b));
	for(int i=0;i<=n;i++)
		for(int j=1;j<(1<<8);j++) 
			f[i][j]=-INF;
	f[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<8);j++)
		{	
			if(f[i][j]!=-INF)
			{
				for(int k=0;k<8;k++)
				{
					if((j&(1<<k))==0)
					{
						int h=x+b[k]-1;
						if(h>=v[k].size()) 
							continue;
						f[v[k][h]+1][j|(1<<k)]=max(f[v[k][h]+1][j|(1<<k)],f[i][j]);
						h++;
						if(h>=v[k].size())
							continue;
						f[v[k][h]+1][j|(1<<k)]=max(f[v[k][h]+1][j|(1<<k)],f[i][j]+1);				
					}
				}
			}
		}
		b[a[i+1]-1]++;
	}
	int cnt=-INF;
	for(int i=0;i<=n;i++) 
		cnt=max(cnt,f[i][(1<<8)-1]);
	return cnt==-INF?-1:x*8+cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) 
		v[a[i]-1].push_back(i-1);
	l=1;r=n>>3;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(check(m)!=-1) 
			ans=max(ans,check(m)),l=m+1;
		else 
			r=m-1;
	}
	if(ans==0) 
		for(int i=0;i<8;i++) 
			if(v[i].size()) 
				ans++;
	printf("%d\n",ans);
	return 0;
}