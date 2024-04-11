#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],b[N],c[N][N],n,m,k;
vector<int>x,y;
int check(int mid)
{
	x.clear(),y.clear();
	for(int i=1;i<=k;i++)
	{
		int u=max(1,a[i]-mid),d=min(n,a[i]+mid);
		int l=max(1,b[i]-mid),r=min(m,b[i]+mid);
		x.push_back(u),x.push_back(d+1);
		y.push_back(l),y.push_back(r+1);
	}
	x.push_back(1),x.push_back(n+1);
	y.push_back(1),y.push_back(m+1);
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	sort(y.begin(),y.end()); 
	y.erase(unique(y.begin(),y.end()),y.end());
	for(int i=0;i<=x.size();i++)
		for(int j=0;j<=y.size();j++)
			c[i][j]=0;
	for(int i=1;i<=k;i++)
	{
		int u=max(1,a[i]-mid),d=min(n,a[i]+mid);
		int l=max(1,b[i]-mid),r=min(m,b[i]+mid);
		u=lower_bound(x.begin(),x.end(),u)-x.begin()+1;
		d=lower_bound(x.begin(),x.end(),d+1)-x.begin()+1;
		l=lower_bound(y.begin(),y.end(),l)-y.begin()+1;
		r=lower_bound(y.begin(),y.end(),r+1)-y.begin()+1;
		c[u][l]++,c[u][r]--,c[d][l]--,c[d][r]++;
	}
	int x1=2e9,x2=0,y1=2e9,y2=0;
	for(int i=1;i<x.size();i++)
	{
		for(int j=1;j<y.size();j++)
		{
			c[i][j]+=c[i][j-1]+c[i-1][j]-c[i-1][j-1];
			if(!c[i][j])
			{
				x1=min(x1,i);
				x2=max(x2,i);
				y1=min(y1,j);
				y2=max(y2,j);
			}
		}
	}
	if(x1==2e9)
		return 1;
	x1=x[x1-1],x2=x[x2]-1,y1=y[y1-1],y2=y[y2]-1;
	return x2-x1<=2*mid&&y2-y1<=2*mid;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a[i],&b[i]);
	int l=-1,r=1e9;
	while(r-l>1)
	{
		int mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%d\n",r);
	return 0;
}