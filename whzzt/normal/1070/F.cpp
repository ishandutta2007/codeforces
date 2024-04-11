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
void gs(vector<int> u,vector<int>&s)
{
	s.pb(0);
	while(u.size())
		s.pb(s.back()+u.back()),u.pop_back();
}
vector<int> u[23],s[23];
int n,a;
char ss[3];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s%d",ss,&a);
		u[atoi(ss)].pb(a);
	}
	for(int i=0;i<=11;++i)
		sort(u[i].begin(),u[i].end()),gs(u[i],s[i]);
	int x=0,y=0,su=0;
	while(u[11].size())
	{
		++x,++y,su+=u[11].back();
		u[11].pop_back();
	}
	int cm=0;
	for(int i=0;i<=u[1].size()&&i<=x;++i)
	{
		int uu=min(u[1].size()-i,u[10].size());
		cm=max(cm,s[1][i+uu]+s[10][uu]+
		s[0][min(min(x-i,y+i),int(u[0].size()))]);
	}
	swap(u[1],u[10]); swap(s[1],s[10]);
	for(int i=0;i<=u[1].size()&&i<=x;++i)
	{
		int uu=min(u[1].size()-i,u[10].size());
		cm=max(cm,s[1][i+uu]+s[10][uu]+
		s[0][min(min(x-i,y+i),int(u[0].size()))]);
	}
	su+=cm;
	cout<<su<<"\n";
}