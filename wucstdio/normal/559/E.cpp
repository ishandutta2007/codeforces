#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Place
{
	int x;
	int id;
	int type;
}a[305];
int n,f[105][305][305],p1[105],p2[105],p3[105],sa[105];
bool cmp(Place a,Place b)
{
	return a.x<b.x;
}
bool cmp2(int x,int y)
{
	return p2[x]<p2[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i*3-2].x=x-y;
		a[i*3-2].id=i;
		a[i*3-2].type=-1;
		a[i*3-1].x=x;
		a[i*3-1].id=i;
		a[i*3-1].type=0;
		a[i*3].x=x+y;
		a[i*3].id=i;
		a[i*3].type=1;
	}
	sort(a+1,a+3*n+1,cmp);
	for(int i=1;i<=3*n;i++)
	{
		if(a[i].type==-1)p1[a[i].id]=i;
		if(a[i].type==0)p2[a[i].id]=i;
		if(a[i].type==1)p3[a[i].id]=i;
	}
	for(int i=1;i<=n;i++)sa[i]=i;
	sort(sa+1,sa+n+1,cmp2);
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=3*n;j++)
	    for(int k=0;k<=3*n;k++)
	      f[i][j][k]=-1;
	f[0][0][1]=0;
	for(int o=1;o<=n;o++)
	{
		int i=sa[o];
		for(int l=1;l<=3*n;l++)
		{
			for(int r=l;r<=3*n;r++)
			{
				if(f[o-1][l][r]<0)continue;
				if(p1[i]<=l)f[o][0][max(r,p2[i])]=max(f[o][0][max(r,p2[i])],f[o-1][l][r]+max(a[p2[i]].x-a[r].x,0));
				else f[o][l][max(r,p2[i])]=max(f[o][l][max(r,p2[i])],f[o-1][l][r]+max(a[p2[i]].x-a[r].x,0));
				if(p2[i]<=l)f[o][0][max(r,p3[i])]=max(f[o][0][max(r,p3[i])],f[o-1][l][r]+max(a[p3[i]].x-a[r].x,0));
				else f[o][l][max(r,p3[i])]=max(f[o][l][max(r,p3[i])],f[o-1][l][r]+max(a[p3[i]].x-a[r].x,0));
			}
		}
		for(int r=1;r<=3*n;r++)
		{
			if(f[o-1][0][r]<0)continue;
			if(p1[i]>r)
			{
				for(int k=r;k<p1[i];k++)
				  f[o][k][p2[i]]=max(f[o][k][p2[i]],f[o-1][0][r]+(a[p2[i]].x-a[k].x));
			}
			f[o][0][max(p2[i],r)]=max(f[o][0][max(p2[i],r)],f[o-1][0][r]+(p2[i]<=r?0:a[p2[i]].x-a[max(p1[i],r)].x));
			if(p2[i]>r)
			{
				for(int k=r;k<p2[i];k++)
				  f[o][k][p3[i]]=max(f[o][k][p3[i]],f[o-1][0][r]+(a[p3[i]].x-a[k].x));
			}
			f[o][0][max(p3[i],r)]=max(f[o][0][max(p3[i],r)],f[o-1][0][r]+(p3[i]<=r?0:a[p3[i]].x-a[max(p2[i],r)].x));
		}
	}
	int ans=0;
	for(int i=0;i<=3*n;i++)
	  ans=max(ans,f[n][0][i]);
	printf("%d\n",ans);
	return 0;
}