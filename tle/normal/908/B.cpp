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
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},g[4];
int n,m;
char ms[2333][2333],op[2333];
int main()
{
	scanf("%d%d",&n,&m);
	int ex,ey,sx,sy;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ms[i]+1);
		for(int j=1;j<=m;++j)
			if(ms[i][j]=='S') sx=i,sy=j,ms[i][j]='.';
			else if(ms[i][j]=='E') ms[i][j]='.',ex=i,ey=j;
		ms[i][0]=ms[i][m+1]='#';
	}
	for(int i=0;i<=m+1;++i) ms[0][i]=ms[n+1][i]='#';
	scanf("%s",op);
	for(int i=0;i<4;++i) g[i]=i;
	int cnt=0;
	do
	{
		int x=sx,y=sy;
		for(int j=0;op[j]&&(x!=ex||y!=ey);++j)
		{
			int k=g[op[j]-48];
			x+=dx[k], y+=dy[k];
			if(ms[x][y]=='#') goto GG;
		}
		if(x!=ex||y!=ey) goto GG;
		++cnt; GG:;
	}while(next_permutation(g,g+4));
	cout<<cnt<<"\n";
}