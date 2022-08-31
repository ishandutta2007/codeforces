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
int n,m,r,c,x,y;
char s[2005][2005];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
pii qs[16000006];
int h=8000003,t=h;
int d[2005][2005];
int main()
{
	memset(d,-1,sizeof d);
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	qs[t++]=pii(r,c); d[r][c]=0;
	while(h^t)
	{
		pii g=qs[h++];
		for(int u=0;u<4;++u)
		{
			pii p(g.fi+dx[u],g.se+dy[u]);
			if(s[p.fi][p.se]!='.'
			||(d[p.fi][p.se]!=-1
			&&d[p.fi][p.se]<=d[g.fi][g.se]+(u==3))) continue;
			d[p.fi][p.se]=d[g.fi][g.se]+(u==3);
			if(u==3) qs[t++]=p;
			else qs[--h]=p;
		}
	}
	int aa=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(d[i][j]==-1) continue;
			int a=d[i][j],b=j-c+a;
			if(a<=x&&b<=y) ++aa;
		}
	cout<<aa<<"\n";
}