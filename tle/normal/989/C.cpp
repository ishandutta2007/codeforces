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
int x[4];
char ms[555][555];
deque<int> q; char bl;
void gett(int x,int y)
{
	if(ms[x-1][y]==bl)
	{
		ms[x-1][y-1]=q.back();
		q.pop_back();
	}
	if(ms[x+1][y]==bl)
	{
		ms[x+1][y]=q.back();
		q.pop_back();
	}
	if(ms[x][y-1]==bl)
	{
		ms[x][y-1]=q.back();
		q.pop_back();
	}
	if(ms[x][y+1]==bl)
	{
		ms[x][y+1]=q.back();
		q.pop_back();
	}
}
int main()
{
	for(int i=0;i<4;++i) cin>>x[i];
	pii mi(1e9,1e9);
	for(int i=0;i<4;++i)
		mi=min(mi,pii(x[i],i));
	bl='A'+mi.se;
	for(int i=1;i<=50;++i)
		for(int j=1;j<=50;++j)
			ms[i][j]=bl;
	for(int i=0;i<4;++i) if(i!=mi.se)
		while(x[i]--) q.pb(i+'A');
	int cx=1,cy=2,cl=2,cr=48;
	for(int i=1;i<mi.fi;++i)
	{
		gett(cx,cy);
		cy+=2;
		if(cy>cr)
		{
			++cx; cy=++cl; --cr;
		}
	}
	vector<pii> r; int g=0;
	for(int i=50;i>=1;i-=2)
		for(int j=1;j<=50;j+=2) r.pb(pii(i,j));
	while(!q.empty())
	{
		char s=q.back(); q.pop_back();
		pii t=r[g++]; ms[t.fi][t.se]=s;
	}
	cout<<50<<" "<<50<<"\n";
	for(int i=1;i<=50;++i,puts(""))
		for(int j=1;j<=50;++j)
			putchar(ms[i][j]);
}