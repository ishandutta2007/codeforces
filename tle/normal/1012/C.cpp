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
int n,a[SZ];
int f[5005][2705][4];
inline void upd(int&a,int b)
{if(a>b)a=b;}
int main()
{
	memset(f,127/3,sizeof f);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	int g=(n+1)/2;
	f[0][0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=g;++j)
			for(int t=0;t<4;++t) if(t!=3)
			{
				upd(f[i][j][(t<<1)&3],f[i-1][j][t]);
				if(t&1) continue; //
				if(!(t&2))
				{
					upd(f[i][j+1][1],
					f[i-1][j][t]+max(a[i-1]-a[i]+1,0)+
					max(a[i+1]-a[i]+1,0));
				}
				else if(i>=2)
				{
					upd(f[i][j+1][1],
					f[i-1][j][t]
					-max(a[i-1]-a[i-2]+1,0)
					+max(a[i-1]-min(a[i-2],a[i])+1,0)
					+max(a[i+1]-a[i]+1,0));
				}
			}
	for(int j=1;j<=g;++j)
	{
		int mx=min(min(f[n][j][0],
		f[n][j][1]),f[n][j][2]);
		printf("%d ",mx);
	}
	puts("");
}