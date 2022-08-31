#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
pii h[105][105*107/2];
int q,N[SZ],K[SZ];
vector<int> aa[SZ];
vector<int> qry[105][105*107/2];
vector<int> ch[SZ];
int an=0,ty[SZ];
vector<int> op;
void dfs(int w,int d=0)
{
//	cerr<<w<<"!"<<ty[w]<<":";
//	for(auto c:ch[w]) cout<<c<<",";
//	cout<<"\n";
	if(!ch[w].size())
	{
		op.pb(w);
		return;
	}
	if(ty[w]==1)
	{
		vector<int> sb;
		int s=ch[w].size();
		for(int t=1;t<s;t+=2)
			sb.pb(ch[w][t]);
		sb.pb(ch[w][0]);
		for(int t=(s-1)-((s-1)&1);t>0;t-=2)
			sb.pb(ch[w][t]);
		for(auto r:sb) dfs(r,d^1);
	}
	else
	{
		vector<int> sb;
		for(auto r:ch[w]) sb.pb(r);
		if(d) reverse(sb.begin(),sb.end());
		for(auto r:sb) dfs(r,d^1);
	}
}
vector<int> cons(int n,int p)
{
//	cerr<<n<<","<<p<<"\n";
	an=n;
	vector<int> st;
	for(int i=1;i<=n;++i) ty[i]=0,ch[i].clear(),st.pb(i);
	int X=1,Y=p;
	while(X!=n)
	{
		pii g=h[X][Y];
		assert(g.fi!=-1);
		int y=g.se%2; g.se/=2;
		int c=g.fi-X+1;
		tie(X,Y)=g;
		++an; ty[an]=y; ch[an].clear();
		for(int j=1;j<=c;++j)
			ch[an].pb(st.back()),st.pop_back();
		reverse(ch[an].begin(),ch[an].end());
		st.pb(an);
	}
	assert(Y==n&&st.size()==1);
	op.clear();
	dfs(an);
	#ifdef LOCAL
	#warning "LOCAL ON"
	assert(op.size()==n);
	int sb=0;
	for(int i=0;i<n;++i)
	{
		vector<int> g;
		for(int j=i;j<n;++j)
		{
			g.pb(op[j]);
			sort(g.begin(),g.end());
			bool ok=1;
			for(int w=0;w<g.size();++w)
				ok&=g[w]==g[0]+w;
			if(ok) ++sb;
		}
	}
//	cerr<<sb<<"?\n";
	assert(sb==p);
	#endif
	return op;
}
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
		scanf("%d%d",N+i,K+i),
		qry[N[i]][K[i]].pb(i);
	for(int n=1;n<=100;++n)
	{
	memset(h,-1,sizeof h);
	h[n][n]=pii(0,0);
	for(int i=n;i>=1;--i)
	{
		for(int j=n*(n+1)/2;j>=0;--j) if(~h[i][j].fi)
		{
			for(int c=2;c<=i;++c)
			{
				h[i-c+1][j+c*(c-1)/2]=pii(i,j*2);
				if(c>=4) h[i-c+1][j+1]=pii(i,j*2+1);
			}
		}
	}
	for(int j=n*(n+1)/2;j>=0;--j)
		if(h[1][j].fi!=-1&&qry[n][j].size())
		{
			auto u=cons(n,j);
			for(auto r:qry[n][j]) aa[r]=u;
		}
	}
	for(int i=1;i<=q;++i)
		if(aa[i].size())
		{
			puts("YES");
			for(auto x:aa[i])
				printf("%d ",x);
			puts("");
		}
		else
			puts("NO");
}