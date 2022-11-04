#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

struct unit
{int w,v,l,r;
};
struct unit a[15010];

struct unit2
{int opt,x,y;
};
struct unit2 q[30010];

int n,m,nq,tot,ans,np=10000019,mod=1000000007;
int fp[1010];
long long f[20][1010];
vector<int> segt[120010];
vector<int> rec;

int get_node()
{int ret;
 if(!rec.empty())
 {	ret=rec.back();
 	rec.pop_back();
 }
 else 
 {	tot++;
 	ret=tot;
 }
 return ret;
}

void calc(int k)
{int i;
 for(i=1;i<=m;i++)
 	ans=(ans+(long long)f[k][i]%mod*fp[i-1]%mod)%mod;
}

void change(int i,int l,int r,int x,int y,int z)
{if(x<=l && y>=r)
 {	segt[i].push_back(z);
 	return;
 }
 if(x>r || y<l) return;
 change(i*2,l,(l+r)/2,x,y,z);
 change(i*2+1,(l+r)/2+1,r,x,y,z);
}

void query(int i,int l,int r,int k)
{int j,p,i1;

 if(l>r) return;

 p=get_node();
 for(j=0;j<=m;j++)
 	f[p][j]=f[k][j];
 for(j=0;j<segt[i].size();j++)
 	for(i1=m;i1>=a[segt[i][j]].w;i1--)
 		f[p][i1]=max(f[p][i1],f[p][i1-a[segt[i][j]].w]+a[segt[i][j]].v);
 if(l==r)
 {	if(q[l].opt==3)
 	{	ans=0;
	 	calc(p);
 		printf("%d\n",ans);
	}
	rec.push_back(p);
	return;
 }
 query(i*2,l,(l+r)/2,p);
 query(i*2+1,(l+r)/2+1,r,p);
 rec.push_back(p);
}

int main()
{int i,j;

 scanf("%d%d",&n,&m);
 
 fp[0]=1;
 for(i=1;i<=m;i++)
 	fp[i]=(long long)fp[i-1]*np%mod;
 
 for(i=1;i<=n;i++)
 	scanf("%d%d",&a[i].v,&a[i].w);
 
 scanf("%d",&nq);	
 
 for(i=1;i<=nq;i++)
 {	scanf("%d",&q[i].opt);
 	if(q[i].opt==1)
 	{	scanf("%d%d",&q[i].x,&q[i].y);
 		n++;
		a[n].v=q[i].x;
		a[n].w=q[i].y;
		a[n].l=i;
	}
	else if(q[i].opt==2)
	{ 	scanf("%d",&q[i].x);	
		a[q[i].x].r=i;
	}
 }

 for(i=1;i<=n;i++)
 {	if(a[i].l==0) a[i].l=0;
 	if(a[i].r==0) a[i].r=nq+1;
 }

 for(i=1;i<=n;i++)
 	change(1,1,nq,a[i].l+1,a[i].r-1,i);

 query(1,1,nq,0);
 
 return 0;
}