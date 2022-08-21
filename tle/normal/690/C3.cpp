#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,fa[666666],deep[666666],fs[666666],ss[666666],ns[666666],S=0;
int vn=0,vx[666666],depth[666666],vs[666666];
namespace st
{
	int rm[666666][23],ly[666666][23],gs[666666];
	void initst(int* a,int n)
	{
		for(int i=1;i<=n;i++) rm[i][0]=a[i], ly[i][0]=i;
		for(int s=1;(1<<s)<=n;s++)
		{
			for(int i=1;i+(1<<s)-1<=n;i++)
			{
				int p=i+(1<<(s-1));
				if(rm[i][s-1]<=rm[p][s-1]) ly[i][s]=ly[i][s-1]; else ly[i][s]=ly[p][s-1];
				rm[i][s]=min(rm[i][s-1],rm[p][s-1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			int gl=1,s=0;
			while(gl<=i) gl<<=1, ++s;
			gs[i]=s-1;
		}
	}
	int rmq(int l,int r,int& y)
	{
		int s=gs[r-l+1],p2=r-(1<<s)+1;
		if(rm[l][s]<rm[p2][s]) y=ly[l][s]; else y=ly[p2][s];
		return min(rm[l][s],rm[p2][s]);
	}
};
int lca(int a,int b)
{
	int s,aa=vs[a],bb=vs[b];
	if(aa>bb) swap(aa,bb);
	st::rmq(aa,bb,s);
	return vx[s];
}
int linkl(int a,int b)
{
	int lc=lca(a,b);
	return deep[a]+deep[b]-deep[lc]*2+1;
}
namespace bcj
{
	int ff[666666],la[666666],lb[666666],ll[666666],maxl;
	void init() {for(int i=1;i<=n;i++) ff[i]=0, la[i]=lb[i]=i, ll[i]=1; maxl=1;}
	int gf(int x)
	{
		return ff[x]?ff[x]=gf(ff[x]):x;
	}
#define UPD(a,b,c) {int p=c; if(p>ans) ans=p, ala=a, alb=b;}
#define UPD2(a,b) UPD(a,b,linkl(a,b))
	void conn(int a,int b)
	{
		int fa=gf(a),fb=gf(b),ans=0,ala,alb;
		if(fa==fb) return;
		int fala=la[fa],falb=lb[fa],fbla=la[fb],fblb=lb[fb];
		UPD(fala,falb,ll[fa]) UPD(fbla,fblb,ll[fb])
		UPD2(fala,fbla) UPD2(fala,fblb) UPD2(falb,fbla) UPD2(falb,fblb)
		ff[fb]=fa; la[fa]=ala; lb[fa]=alb; ll[fa]=ans; maxl=max(maxl,ans);
	}
};
void setchild(int x,int f)
{
	fa[x]=f; ++S; ns[S]=fs[f]; fs[f]=S; ss[S]=x;
}
void dfs(int x,int dep=0)
{
	++vn; vx[vn]=x; depth[vn]=dep; vs[x]=vn; deep[x]=dep;
	for(int g=fs[x];g;g=ns[g])
	{
		dfs(ss[g],dep+1); ++vn; vx[vn]=x; depth[vn]=dep;
	}
}
#define BUFSIZE 500000
namespace fib {char b[BUFSIZE]={},*f=b;}
#define gc ((*fib::f)?(*(fib::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
inline const int& ri(int& x)
{
	int tmp=0; bool fu=0; char s;
	while(s=gc,s!='-'&&(s<'0'||s>'9')) ;
	if(s=='-') fu=1; else tmp=s-'0';
	while(s=gc,s>='0'&&s<='9') tmp=tmp*10+s-'0';
	if(fu) return x=-tmp; else return x=tmp;
}
inline int _gi() {int p; ri(p); return p;}
#define gi _gi()
bool ok[666666];
#define pc(x) (putchar(x))
namespace ib {char b[100];}
inline void pll(long long x)
{
	if(x==0) {pc(48); return;}
	if(x<0) {pc('-'); x=-x;}
	char *s=ib::b;
	while(x) *(++s)=x%10, x/=10;
	while(s!=ib::b) pc((*(s--))+48);
}
int main()
{
	n=gi;
	for(int i=2;i<=n;i++)
	{
		int a=gi; setchild(i,a);
	}
	dfs(1); st::initst(depth,vn); bcj::init();
	ok[1]=1;
	for(int x=2;x<=n;x++)
	{
		ok[x]=1;
		for(int g=fs[x];g;g=ns[g])
		{
			int s=ss[g];
			if(ok[s]) bcj::conn(x,s);
		}
		if(ok[fa[x]]) bcj::conn(x,fa[x]);
		printf("%d ",bcj::maxl-1);
	}
}