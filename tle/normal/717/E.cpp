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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 666666
int n,col[SZ];
Edg
int oo[23333333],on=0;
void dfs(int x,int f)
{
	oo[++on]=x; col[x]^=1;
	bool down=0;
	for es(x,e)
	{
		int b=vb[e]; if(b==f) continue;
		dfs(b,x); oo[++on]=x, col[x]^=1;
	}
	if(col[x]&&x!=1)
	{
	oo[++on]=f, col[f]^=1;
	oo[++on]=x; col[x]^=1;
	}
}
//bool colp[SZ];
//map<int,int> rs[2333];
int main()
{
	scanf("%d",&n);
	int cc=0,p;
	for(int i=1;i<=n;i++)
	scanf("%d",col+i), col[i]=col[i]<0, cc+=col[i];
	for(int i=1;i<n;i++)
	{ 
		int a,b; scanf("%d%d",&a,&b);
		//a=rand()%i+1, b=i+1;
		//cout<<a<<","<<b<<"\n";
		if(a>b) swap(a,b);
		if(a==1) p=b;
		//rs[a][b]=rs[b][a]=1;
		adde(a,b);
	}
	if(cc==1&&col[1])
	{
		printf("1 %d 1 %d\n",p,p);
		return 0;
	}
	col[1]^=1;
	dfs(1,0);
	if(col[1])
	{
		if(oo[on]==1) --on;
		else oo[++on]=1;
	}
	/*
	for(int i=2;i<=on;i++) if(rs[oo[i]][oo[i-1]]!=1) cout<<"WA\n";
	for(int i=2;i<=on;i++) colp[oo[i]]^=1;
	for(int i=1;i<=n;i++) if(colp[i]) cout<<"WA\n";*/
	for(int i=1;i<=on;i++) printf("%d ",oo[i]);
}