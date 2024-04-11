#include<bits/stdc++.h>
using namespace std;
const int max_n=14+5;
int xa[max_n],ya[max_n];
const int max_m=100+5;
int xb[max_m],yb[max_m],t[max_m];
struct Quest
{
	int x,y,t;
}Q[max_m];
inline bool operator < (const Quest &a,const Quest &b)
{
	return a.t<b.t;
}
const int max_S=1<<14|5;
int F[max_S][max_m],G[max_S][max_m],d1[max_n][max_S],d2[max_m][max_S],d3[max_m][max_n],d4[max_m][max_m],Log[max_S],d_now[max_m];
const int inf=0x3f3f3f3f;
inline int dis(int a,int b,int c,int d)
{
	return (c>=a?c-a:a-c)+(d>=b?d-b:b-d);
}
inline void chk_mn(int &x,int y)
{
	x=min(x,y);
}
inline void chk_mx(int &x,int y)
{
	x=max(x,y);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d%d",xa+i,ya+i);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].t);
	sort(Q+1,Q+m+1);
	for(int i=1;i<=m;++i)
		xb[i]=Q[i].x,yb[i]=Q[i].y,t[i]=Q[i].t;
	int Full=(1<<n)-1;
	Log[0]=-1;
	for(int S=1;S<=Full;++S)
		Log[S]=Log[S>>1]+1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			d_now[j]=dis(xa[i],ya[i],xa[j],ya[j]);
		d1[i][0]=inf;
		for(int S=1;S<=Full;++S)
		{
			int k=Log[S],T=S^(1<<k);
			d1[i][S]=min(d1[i][T],d_now[k]);
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<n;++j)
			d_now[j]=dis(xb[i],yb[i],xa[j],ya[j]);
		d2[i][0]=inf;
		for(int S=1;S<=Full;++S)
		{
			int k=Log[S],T=S^(1<<k);
			d2[i][S]=min(d2[i][T],d_now[k]);
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=0;j<n;++j)
			d3[i][j]=dis(xb[i],yb[i],xa[j],ya[j]);
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			d4[i][j]=dis(xb[i],yb[i],xb[j],yb[j]);
	for(int S=0;S<=Full;++S)
		for(int i=0;i<=m;++i)
			F[S][i]=inf,G[S][i]=-inf;
	for(int x=0;x<n;++x)
		F[1<<x][0]=0;
	for(int q=1;q<=m;++q)
		G[0][q]=1;
	for(int mask=0;mask<=Full;++mask)
	{
		for(int d=0;d<m;++d)
			for(int q=d+1;q<=m;++q)
			{
				if(F[mask][d]+d2[q][mask]<=t[q])
					chk_mx(G[mask][q],d+1);
			}
		for(int q1=1;q1<m;++q1)
			for(int q2=q1+1;q2<=m;++q2)
			{
				if(t[q1]+min(d4[q1][q2],d2[q2][mask])<=t[q2])
					chk_mx(G[mask][q2],G[mask][q1]+1);
			}
		for(int x=0;x<n;++x)
		{
			if(~mask>>x&1)
			{
				int mask_new=mask|(1<<x);
				for(int d=0;d<=m;++d)
					chk_mn(F[mask_new][d],F[mask][d]+d1[x][mask]);
				for(int q=1;q<=m;++q)
				{
					int v=G[mask][q];
					if(v>0)
						chk_mn(F[mask_new][v],t[q]+min(d3[q][x],d1[x][mask]));
				}
			}
		}
	}
	int ans=0;
	for(int mask=0;mask<=Full;++mask)
		for(int q=1;q<=m;++q)
			ans=max(ans,G[mask][q]);
	printf("%d\n",ans);
	return 0;
}