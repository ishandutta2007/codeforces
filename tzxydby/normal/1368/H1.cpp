#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=1e9;
int n,m,q,t;
char s0[N],s1[N];
struct seg
{
	int f;
	struct nd
	{
		int v[2][2][2],s[2][2];
		nd(){}
		nd(int v0,int v1)
		{
			v[0][0][0]=v0+v1,v[0][1][1]=!v0+!v1;
			v[1][0][0]=v0+!v1,v[1][1][1]=!v0+v1;
			v[0][0][1]=v[0][1][0]=v[1][0][1]=v[1][1][0]=inf;
			s[0][v0]=s[1][v1]=1;
			s[0][!v0]=s[1][!v1]=0;
		}
		friend nd operator + (nd a,nd b)
		{
			nd c;
			for(int i=0;i<2;i++)
			{
				for(int x=0;x<2;x++)
				{
					for(int y=0;y<2;y++)
					{
						c.v[i][x][y]=inf;
						for(int j=0;j<2;j++)
							for(int k=0;k<2;k++)
								c.v[i][x][y]=min(c.v[i][x][y],a.v[i][x][j]+b.v[i][k][y]+(j!=k)*t);
					}
				}
			}
			for(int i=0;i<2;i++)
				for(int x=0;x<2;x++)
					c.s[i][x]=a.s[i][x]+b.s[i][x];
			return c;
		}
	}tr[N<<2];
	int tag[N<<2];
	void at(int k,int r)
	{
		tag[k]^=r;
		if(r&1)
		{
			for(int i=0;i<2;i++)
				swap(tr[k].s[i][0],tr[k].s[i][1]);
			for(int i=0;i<2;i++)
				for(int y=0;y<2;y++)
					swap(tr[k].v[i][0][y],tr[k].v[i][1][!y]);
			r^=3;
		}
		if(r&2)
		{
			swap(tr[k].s[1][0],tr[k].s[1][1]);
			for(int x=0;x<2;x++)
				for(int y=0;y<2;y++)
					swap(tr[k].v[0][x][y],tr[k].v[1][x][y]);
		}
	}
	void pd(int k)
	{
		if(tag[k])
		{
			at(k<<1,tag[k]);
			at(k<<1|1,tag[k]);
			tag[k]=0;
		}
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]=nd(s0[l]=='R',s1[l]=='R');
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		t=f;
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
	void upd(int k,int l,int r,int a,int b,int x)
	{
		if(l==a&&r==b)
		{
			at(k,x);
			return;
		}
		pd(k);
		int mid=l+r>>1;
		if(b<=mid) upd(k<<1,l,mid,a,b,x);
		else if(a>mid) upd(k<<1|1,mid+1,r,a,b,x);
		else upd(k<<1,l,mid,a,mid,x),upd(k<<1|1,mid+1,r,mid+1,b,x);
		t=f;
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
}t1,t2;
int sol()
{
	int ans=inf;
	for(int x=0;x<2;x++)
	{
		for(int y=0;y<2;y++)
		{
			ans=min(ans,t1.tr[1].v[0][x][y]+t2.tr[1].s[0][!x]+t2.tr[1].s[1][!y]);
			ans=min(ans,t2.tr[1].v[0][x][y]+t1.tr[1].s[0][!x]+t1.tr[1].s[1][!y]);
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",s0+1,s1+1);
	t1.f=m,t1.build(1,1,n);
	scanf("%s%s",s0+1,s1+1);
	t2.f=n,t2.build(1,1,m);	
	printf("%d\n",sol());
	while(q--)
	{
		char b[5];
		int l,r;
		scanf("%s%d%d",b,&l,&r);
		if(b[0]=='L')
			t1.upd(1,1,n,l,r,1);
		if(b[0]=='R')
			t1.upd(1,1,n,l,r,2);
		if(b[0]=='U')
			t2.upd(1,1,m,l,r,1);
		if(b[0]=='D')
			t2.upd(1,1,m,l,r,2);
		printf("%d\n",sol());
	}
	return 0;
}