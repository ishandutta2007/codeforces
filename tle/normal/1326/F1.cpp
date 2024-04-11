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
ll f[1<<15][390];
int N[20],n;
map<vector<int>,int> cf[20];
vector<int> v,rv[20][9999];
void dfs(int cs,int u,int ub)
{
	cf[cs][v]=++N[cs],rv[cs][N[cs]]=v;
	for(int d=u;d+cs<=ub;++d)
		v.pb(d),dfs(cs+d,d,ub),v.pop_back();
}
int go[20][390][20];
char g[20][20];
ll ch[1<<20],tt[390];
ll f2[1<<18][18];
ll ans[1<<18];
#define pc __builtin_popcount
int main()
{
	dfs(0,1,18);
	for(int i=0;i<=18;++i)
		for(int j=1;j<=N[i];++j)
			for(int k=1;i+k<=18;++k)
			{
				vector<int> w=rv[i][j];
				w.pb(k);
				sort(w.begin(),w.end());
				go[i][j][k]=cf[i+k][w];
				assert(go[i][j][k]!=0);
			}
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>g[i];
	//start of chain
	for(int i=0;i<n;++i)
	{
		memset(f2,0,sizeof f2);
		f2[1<<i][i]=1;
		for(int x=0;x<(1<<n);++x)
			for(int y=0;y<n;++y) if(f2[x][y])
			{
				ch[x]+=f2[x][y];
				for(int k=0;k<n;++k) if(!(x&(1<<k))&&g[y][k]=='1')
					f2[x|(1<<k)][k]+=f2[x][y];
			}
	}
	f[0][1]=1;
	for(int i=0;i<n;++i)
	{
		for(int o=0;o<(1<<i);++o)
			for(int a=0;a<390;++a) if(f[o][a])
			{
				int w=((1<<i)-1)^o,*po=go[pc(o)][a];
				for(int u=w;;u=(u-1)&w)
				{
					f[u|o|(1<<i)][po[pc(u)+1]]
					+=f[o][a]*ch[u|(1<<i)];
					if(u==0) break;
				}
			}
	}
	for(int j=0;j<(1<<(n-1));++j)
	{
		static int p[30],cn[30];
		memset(cn,0,sizeof cn);
		//search thru 1 substr
		for(int i=0;i<n;++i) p[i]=(j>>i)&1;
		int x=0,y=1,g=0;
		ll F=1;
		for(int i=0;i<n;++i)
		{
			if(p[i]) ++g;
			else
			{
				if(g)
				{
					++g;
					y=go[x][y][g];
					x+=g;
					F*=++cn[g];
				}
				g=0;
			}
		}
		while(x<n)
			y=go[x][y][1],++x,F*=++cn[1];
		F*=f[(1<<n)-1][y];
		ans[j]=F;
	}
	for(int k=0;k<n-1;++k)
		for(int j=0;j<(1<<(n-1));++j)
			if(j&(1<<k)) ans[j^(1<<k)]=ans[j^(1<<k)]-ans[j];
	for(int j=0;j<(1<<(n-1));++j) cout<<ans[j]<<" ";
}