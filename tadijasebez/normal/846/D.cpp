#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=550;
int matrix[N][N];
struct Query
{
	int x,y,t;
	inline bool operator < (const Query &b) const
	{
		return t<b.t;
	}
} broken[N*N];
void Initialize(int n, int m)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			matrix[i][j]=0;
		}
	}
}
void Set(int x, int y, int n, int m)
{
	int i,j;
	for(i=x;i<=n;i+=i&-i)
	{
		for(j=y;j<=m;j+=j&-j)
		{
			matrix[i][j]++;
		}
	}
}
int Get(int x, int y, int n, int m)
{
	if(x>n) x=n;
	if(y>m) y=m;
	if(x<0) x=0;
	if(y<0) y=0;
	int ans=0,i,j;
	for(i=x;i>0;i-=i&-i)
	{
		for(j=y;j>0;j-=j&-j)
		{
			ans+=matrix[i][j];
		}
	}
	return ans;
}
int Get(int x1, int y1, int k, int n, int m)
{//printf(":D");
	return Get(x1+k,y1+k,n,m)+Get(x1-1,y1-1,n,m)-Get(x1+k,y1-1,n,m)-Get(x1-1,y1+k,n,m);
}
int main()
{
	int n,m,k,q,i,j;
	scanf("%i %i %i %i",&n,&m,&k,&q);
	for(i=0;i<q;i++)
	{
		scanf("%i %i %i",&broken[i].x,&broken[i].y,&broken[i].t);
	}
	sort(broken,broken+q);
	int top=q-1;
	int bot=0;
	int mid,sol=-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		Initialize(n,m);
		for(i=0;i<=mid;i++)
		{
			Set(broken[i].x,broken[i].y,n,m);
		}
		bool ok=false;
		for(i=1;i<=n-k+1;i++)
		{
			for(j=1;j<=m-k+1;j++)
			{
				if(Get(i,j,k-1,n,m)==k*k) ok=true;
			}
		}
		if(ok) sol=broken[mid].t,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",sol);
	return 0;
}