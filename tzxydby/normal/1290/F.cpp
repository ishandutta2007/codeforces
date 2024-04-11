#include<bits/stdc++.h>
using namespace std;
const int N=32,mod=998244353;
int f[N][N][N][N][N][2][2],n,m,x[N],y[N];
int dfs(int h,int a,int b,int c,int d,int p,int q)
{
	if(h==30)
		return !a&&!b&&!c&&!d&&!p&&!q;
	int &v=f[h][a][b][c][d][p][q];
	if(v!=-1)
		return v;
	v=0;
	int ra=a,rb=b,rc=c,rd=d,rp=p,rq=q;
	for(int s=0;s<(1<<n);s++)
	{
		a=ra,b=rb,c=rc,d=rd,p=rp,q=rq;
		for(int i=0;i<n;i++)
		{
			if(s>>i&1)
			{
				if(x[i]>0)
					a+=x[i];
				if(x[i]<0)
					b-=x[i];
				if(y[i]>0)
					c+=y[i];
				if(y[i]<0)
					d-=y[i];
			}
		}
		if((a&1)>(m>>h&1))
			p=1;
		if((a&1)<(m>>h&1))
			p=0;
		if((c&1)>(m>>h&1))
			q=1;
		if((c&1)<(m>>h&1))
			q=0;
		if((a&1)!=(b&1))
			continue;
		if((c&1)!=(d&1))
			continue;
		a>>=1,b>>=1,c>>=1,d>>=1;
		v=(v+dfs(h+1,a,b,c,d,p,q))%mod;
	}
	return v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	memset(f,-1,sizeof(f));
	printf("%d\n",(dfs(0,0,0,0,0,0,0)+mod-1)%mod);
	return 0;
}