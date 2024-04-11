#include<stdio.h>
#include<string.h>
#define fr(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int p=777777777;
int f[3][3];
struct N
{
	ll a[3][3];
	int l,r;
	N *L,*R;
	void ud()
	{
		memset(a,0,sizeof a);
		fr(i,3)
			fr(j,3)
				if(f[i][j])
					fr(k,3)
						fr(l,3)
							a[k][l]=(a[k][l]+L->a[k][i]*R->a[j][l])%p;
	}
	void mk(int w)
	{
		memset(a,0,sizeof a);
		if(w)
			a[w-1][w-1]=1;
		else
			fr(i,3)
				a[i][i]=1;
	}
	N *bd(int l,int r)
	{
		this->l=l;
		this->r=r;
		if(l==r)
			mk(0);
		else
		{
			int m=(l+r)/2;
			L=(new N())->bd(l,m);
			R=(new N())->bd(m+1,r);
			ud();
		}
		return this;
	}
	void cg(int x,int y)
	{
		if(l==r)
			mk(y);
		else
		{
			int m=(l+r)/2;
			if(x>m)
				R->cg(x,y);
			else
				L->cg(x,y);
			ud();
		}
	}
	int S()
	{
		int s=0;
		fr(i,3)
			fr(j,3)
				s=(s+a[i][j])%p;
		return s;
	}
};
int x,y,n,m;
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,3)
		fr(j,3)
			scanf("%d",f[i]+j);
	N*rt=(new N())->bd(1,n);
	fr(i,m)
	{
		scanf("%d%d",&x,&y);
		rt->cg(x,y);
		printf("%d\n",rt->S());
	}
	return 0;
}