#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,_sum[4000005],*sum[1000005],_c[4000005],*c[1000005];
char _s[4000005],*s[1000005],_t[4000005],*t[3000005];
int S(int i,int j,int i2,int j2)
{
	return sum[i2][j2]-sum[i-1][j2]-sum[i2][j-1]+sum[i-1][j-1];
}
bool check(int v)
{
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=m;j++)
	    c[i][j]=0;
	for(int i=v+1;i<=n-v;i++)
	  for(int j=v+1;j<=m-v;j++)
	    if(S(i-v,j-v,i+v,j+v)==(2*v+1)*(2*v+1))
	    {
	    	c[i-v][j-v]++;
			if(i+v+1<=n)c[i+v+1][j-v]--;
			if(j+v+1<=m)c[i-v][j+v+1]--;
			if(i+v+1<=n&&j+v+1<=m)c[i+v+1][j+v+1]++;
		}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+c[i][j];
		if(c[i][j]==0&&s[i][j]=='X')return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	s[0]=_s;
	t[0]=_t;
	sum[0]=_sum;
	c[0]=_c;
	for(int i=1;i<=n;i++)
	{
		s[i]=_s+i*(m+1);
		t[i]=_t+i*(m+1);
		c[i]=_c+i*(m+1);
		sum[i]=_sum+i*(m+1);
		scanf("%s",s[i]+1);
	}
	s[n+1]=_s+(n+1)*(m+1);
	t[n+1]=_t+(n+1)*(m+1);
	sum[n+1]=_sum+(n+1)*(m+1);
	c[n+1]=_c+(n+1)*(m+1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='X');
	int l=0,r=min(n,m)/2;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	int v=r;
	memset(_c,0,sizeof(_c));
	for(int i=v+1;i<=n-v;i++)
	  for(int j=v+1;j<=m-v;j++)
	    if(S(i-v,j-v,i+v,j+v)==(2*v+1)*(2*v+1))
	      c[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j])putchar('X');
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;
}