#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
int p=777777777;
struct N
{
	ll a[3][3];
	int w,l,r;
}t[300020];
int f[3][3];
void mg(ll a[3][3],ll b[3][3],ll c[3][3])
{
	ll o[3][3];
	memset(a,0,sizeof o);
	fr(i,3)
		fr(j,3)
			if(f[i][j])
				fr(k,3)
					fr(l,3)
						a[k][l]=(a[k][l]+b[k][i]*c[j][l])%p;
	return;
}
void bd(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	if(l==r)
	{
		memset(t[x].a,0,sizeof t[x].a);
		if(t[x].w==0)
		{
			t[x].a[0][0]=1;
			t[x].a[1][1]=1;
			t[x].a[2][2]=1;
		}
		else
		{
			t[x].a[t[x].w-1][t[x].w-1]=1;
		}
		return;
	}
	int m=(l+r)/2;
	bd(x*2,l,m);
	bd(x*2+1,m+1,r);
	mg(t[x].a,t[x*2].a,t[x*2+1].a);
}
void R(int x,int p,int w)
{
	if(t[x].l==t[x].r)
	{
		t[x].w=w;
		memset(t[x].a,0,sizeof t[x].a);
		if(t[x].w==0)
		{
			t[x].a[0][0]=1;
			t[x].a[1][1]=1;
			t[x].a[2][2]=1;
		}
		else
		{
			t[x].a[t[x].w-1][t[x].w-1]=1;
		}
		return;
	}
	int m=(t[x].l+t[x].r)/2;
	if(p<=m)
		R(x*2,p,w);
	else
		R(x*2+1,p,w);
	mg(t[x].a,t[x*2].a,t[x*2+1].a);
}
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,3)
		fr(j,3)
			scanf("%d",f[i]+j);
	bd(1,1,n);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		R(1,x,y);
		ll s=0;
		fr(i,3)
			fr(j,3)
				s+=t[1].a[i][j];
		printf("%I64d\n",(s+p)%p);
	}
	return 0;
}