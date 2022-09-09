#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=100050;
const int M=8*17*N;
const int inf=1e9+7;
int root[N],sum[M],tsz,ls[M],rs[M];
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++tsz;
	sum[c]+=f;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
void Set(int i, int j, int f){ for(;i<N;i+=i&-i) Set(root[i],1,N,j,f);}
int Get(int i, int l, int r){ int ret=0;for(;i;i-=i&-i) ret+=Get(root[i],1,N,l,r);return ret;}
int Get(int l, int r, int x, int y){ return Get(r,x,y)-Get(l-1,x,y);}
struct Query
{
	int z,xl,xr,yl,yr,t,id;
	Query(){}
	Query(int _z, int _xl, int _xr, int _yl, int _yr, int _t, int _id){ z=_z,xl=_xl,xr=_xr,yl=_yl,yr=_yr,t=_t,id=_id;}
	bool operator < (Query b) const { return z<b.z;}
};
struct Point
{
	int x,y,z;
	Point(){}
	Point(int _x, int _y, int _z){ x=_x,y=_y,z=_z;}
	bool operator < (Point b) const { return z<b.z;}
};
vector<Query> Qs;
vector<Point> Ps;
int xl=inf,xr=-inf,yl=inf,yr=-inf,zl=inf,zr=-inf;
int sol[N],ans[N];
int main()
{
	int n,m,q,i,h,x,y,z;
	scanf("%i %i %i %i %i %i",&h,&h,&h,&n,&m,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&x,&y,&z);
		xl=min(xl,x);
		xr=max(xr,x);
		yl=min(yl,y);
		yr=max(yr,y);
		zl=min(zl,z);
		zr=max(zr,z);
	}
	bool correct=1;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&x,&y,&z);
		if(xl<=x && xr>=x && yl<=y && yr>=y && zl<=z && zr>=z) correct=0;
		Ps.pb(Point(x,y,z));
	}
	sort(Ps.begin(),Ps.end());
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&x,&y,&z);
		if(xl<=x && xr>=x && yl<=y && yr>=y && zl<=z && zr>=z) ans[i]=1;
		else
		{
			Qs.pb(Query(min(zl,z)-1,min(xl,x),max(xr,x),min(yl,y),max(yr,y),-1,i));
			Qs.pb(Query(max(zr,z),min(xl,x),max(xr,x),min(yl,y),max(yr,y),1,i));
		}
	}
	if(!correct) return printf("INCORRECT\n"),0;
	printf("CORRECT\n");
	sort(Qs.begin(),Qs.end());
	int j=0;
	for(i=0;i<Qs.size();i++)
	{
		while(j<Ps.size() && Ps[j].z<=Qs[i].z) Set(Ps[j].x,Ps[j].y,1),j++;
		sol[Qs[i].id]+=Get(Qs[i].xl,Qs[i].xr,Qs[i].yl,Qs[i].yr)*Qs[i].t;
	}
	for(i=1;i<=q;i++)
	{
		if(ans[i]!=1)
		{
			if(sol[i]>0) ans[i]=2;
			else ans[i]=3;
		}
	}
	for(i=1;i<=q;i++)
	{
		if(ans[i]==1) printf("OPEN\n");
		if(ans[i]==2) printf("CLOSED\n");
		if(ans[i]==3) printf("UNKNOWN\n");
	}
    return 0;
}