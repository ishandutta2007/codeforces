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
#define SZ 1234567
int T,n;
vector<int> s[SZ];
char col[SZ];
int js()
{
	for(int i=1;i<=n;++i)
		if(col[i]=='W')
		{
			int ans=0;
			for(auto g:s[i])
				ans+=col[g]=='W';
			if(ans>=2) return 1;
		}
	for(int i=1;i<=n;++i)
		if(col[i]=='B')
		{
			int ans=0;
			for(auto g:s[i])
				ans+=col[g]=='B';
			if(ans>=2) return -1;
		}
	return 0;
}
bool brute(int cur)
{
	int w=js();
	if(w==1) return 1;
	if(w==-1) return 0;
	bool poss=0;
	for(int i=1;i<=n;++i)
		if(col[i]=='N')
		{
			poss=1;
			if(!cur)
			{
				col[i]='W';
				if(brute(!cur))
				{
					col[i]='N';
					return 1;
				}
				col[i]='N';
			}
			else
			{
				col[i]='B';
				if(!brute(!cur))
				{
					col[i]='N';
					return 0;
				}
				col[i]='N';
			}
		}
	if(!poss) return 0;
	return cur;
}
int dep[SZ];
void dfs(int x,int fa=0)
{
	dep[x]=dep[fa]+1;
	for(auto b:s[x]) if(b!=fa)
		dfs(b,x);
}
bool sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) s[i].clear();
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),
		s[a].pb(b),s[b].pb(a);
	scanf("%s",col+1);
	if(n<=5) return brute(0);
	for(int i=1;i<=n;++i)
		if(s[i].size()>=4) return 1;
	for(int i=1;i<=n;++i)
		if(s[i].size()==3)
		{
			int c2=0;
			for(auto g:s[i])
				c2+=s[g].size()>1;
			if(c2>=2) return 1;
		}
	for(int i=1;i<=n;++i)
		if(col[i]=='W')
		{
			if(s[i].size()>1) return 1;
			int g=s[i].front();
			if(s[g].size()>=3) return 1;
		}
	dfs(1);
	int g[2]={0,0};
	for(int i=1;i<=n;++i)
		if(col[i]=='W') g[dep[i]&1]++;
	for(int i=1;i<=n;++i)
		if(s[i].size()==3) g[!(dep[i]&1)]++;
	if(g[0]>1||g[1]>1) return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		if(sol()) puts("White");
		else puts("Draw");
}