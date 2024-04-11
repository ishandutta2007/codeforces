#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const long long inf=1e18;
int n,q,x[2][N],y[2][N],d[N][2][2];
struct nd{int l,r;long long v[2][2];}tr[N<<2];
nd operator+(nd a,nd b)
{
	nd c;
	c.l=a.l,c.r=b.r;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c.v[i][j]=inf;
			for(int p=0;p<2;p++)
				for(int q=0;q<2;q++)
					c.v[i][j]=min(c.v[i][j],a.v[i][p]+b.v[q][j]+d[a.r][p][q]);
		}
	}
	return c;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k].l=tr[k].r=l;
		tr[k].v[0][0]=tr[k].v[1][1]=0;
		tr[k].v[0][1]=tr[k].v[1][0]=inf;
		return;
	}
	int md=l+r>>1;
	build(k<<1,l,md);
	build(k<<1|1,md+1,r);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
nd ask(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int md=l+r>>1;
	if(b<=md) return ask(k<<1,l,md,a,b);
	else if(a>md) return ask(k<<1|1,md+1,r,a,b);
	else return ask(k<<1,l,md,a,md)+ask(k<<1|1,md+1,r,md+1,b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d%d%d",&x[0][i],&y[0][i],&x[1][i],&y[1][i]);
	for(int i=1;i<n;i++)
	{
		for(int p=0;p<2;p++)
		{
			for(int q=0;q<2;q++)
			{
				int px=x[p][i],py=y[p][i];
				if(p) py++;
				else px++;
				d[i][p][q]=abs(px-x[q][i+1])+abs(py-y[q][i+1])+1;
			}
		}
	}
	build(1,1,n-1);
	scanf("%d",&q);
	while(q--)
	{
		int xl,yl,xr,yr,gl,gr;
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		gl=max(xl,yl),gr=max(xr,yr);
		if(gl>gr) swap(xl,xr),swap(yl,yr),swap(gl,gr);
		if(gl==gr)
			printf("%d\n",abs(xl-xr)+abs(yl-yr));
		else
		{
			nd v=ask(1,1,n-1,gl,gr-1);
			long long ans=inf;
			for(int p=0;p<2;p++)
				for(int q=0;q<2;q++)
					ans=min(ans,v.v[p][q]+abs(xl-x[p][gl])+abs(yl-y[p][gl])+abs(xr-x[q][gr-1]-(q==0))+abs(yr-y[q][gr-1]-(q==1))+1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}