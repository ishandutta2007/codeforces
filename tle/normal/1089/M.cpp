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
int n; Edg
bool ins[SZ]; int low[SZ],dfn[SZ],C=0,st[SZ],sn,bl[SZ],B;
vector<int> vs[SZ];
void dfs(int x)
{
	low[x]=dfn[x]=++C; ins[x]=1; st[++sn]=x;
	for esb(x,e,b)
		if(!dfn[b]) dfs(b),low[x]=min(low[x],low[b]);
		else if(ins[b]) low[x]=min(low[x],dfn[b]);
	if(low[x]!=dfn[x]) return; ++B;
	while(1)
	{
		int p=st[sn--];
		bl[p]=B; vs[B].pb(p);
		ins[p]=0;
		if(p==x) break;
	}
}
vector<int> py[SZ];
char sb[55][505][605];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int x; scanf("%d",&x);
			if(x) ad_de(i,j);
		}
	for(int i=1;i<=n;++i)
		if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;++i)
		for esb(i,e,b)
			if(bl[i]!=bl[b])
				py[bl[i]].pb(bl[b]);
	int N=5*n,M=420,E=13,H=n*5+1;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			for(int k=0;k<=H;++k) sb[i][j][k]='.';
	for(int i=1;i<=B;++i)
		for(int x=1;x<=N;++x)
			for(int y=1;y<=M;++y)
				sb[x][y][i*5+2]='#';
	//for(int i=1;i<=B;++i)
		//i, x=i*20, 1..M
	for(int i=B;i>=1;--i)
	{
		for(auto g:py[i])
		{
			if(i<=g) throw "GG";
			E+=4; int X=i*5,Y=i*5;
			while((--X)!=g*5)
				sb[X][E][Y]='#';
			for(int p=g;p<i;++p)
			{
			sb[g*5][E][p*5+2]='.';
			sb[g*5][E-1][p*5+3]=sb[g*5][E-1][p*5+4]='#';
			sb[g*5][E+1][p*5+3]=sb[g*5][E+1][p*5+4]='#';
			sb[g*5-1][E][p*5+3]=sb[g*5-1][E][p*5+4]='#';
			sb[g*5+1][E][p*5+3]=sb[g*5+1][E][p*5+4]='#';
			}
		}
		for(int j=1;j<=E;++j)
			sb[i*5][j][i*5]='#';
		for(int k=0;k<vs[i].size();++k)
			sb[i*5][k+1][i*5+1]=vs[i][k]+48;
	}
	cout<<M<<" "<<N<<" "<<H+2<<"\n";
	for(int i=H;i>=-1;--i)
	{
		for(int x=1;x<=N;++x,puts(""))
			for(int y=1;y<=M;++y)
				putchar(sb[x][y][max(i,0)]);
		puts("");
	}
}