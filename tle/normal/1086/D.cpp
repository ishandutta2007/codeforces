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
int n,q,v[SZ];
char u[SZ];
set<int> g[3];
char cv[233];
struct BS
{
int b[SZ];
void edt(int x,int y)
{
	for(;x<=n;x+=x&-x) b[x]+=y;
}
int qs(int x)
{
	int s=0;
	for(;x>=1;x-=x&-x) s+=b[x];
	return s;
}
int qry(int l,int r)
{return qs(r)-qs(l-1);}
}S[3];
int qry()
{
	int ans=0;
	for(int i=0;i<3;++i)
	{
		if(g[(i+1)%3].empty())
		{
			ans+=g[i].size();
			continue;
		}
		if(g[(i+2)%3].empty()) continue;
		int A=*g[(i+2)%3].begin(),B=*(--g[(i+2)%3].end());
		ans+=S[i].qry(A,B);
		int X=*g[(i+1)%3].begin(),Y=*(--g[(i+1)%3].end());
		ans+=S[i].qry(1,min(A,X)-1);
		ans+=S[i].qry(max(B,Y)+1,n);
	}
	return ans;
}
int main()
{
	cv['R']=0; cv['P']=1; cv['S']=2;
	scanf("%d%d%s",&n,&q,u+1);
	for(int i=1;i<=n;++i)
		v[i]=cv[u[i]],g[v[i]].insert(i),S[v[i]].edt(i,1);
	printf("%d\n",qry());
	while(q--)
	{
		int x,y; char s[3];
		scanf("%d%s",&x,s);
		y=cv[s[0]];
		S[v[x]].edt(x,-1);
		g[v[x]].erase(x);
		v[x]=y;
		g[v[x]].insert(x);
		S[v[x]].edt(x,1);
		printf("%d\n",qry());
	}
}