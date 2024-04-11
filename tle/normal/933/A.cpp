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
#define SZ 2099
int f[SZ][SZ][2][2],fr[SZ][SZ][2][2],n,a[SZ];
inline void cm(int&a,int b) {if(a<b) a=b;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i),--a[i];
	for(int j=1;j<=n;++j)
		for(int i=j;i>=1;--i)
			for(int k=0;k<2;++k)
				for(int g=0;g<2;++g)
				{
					cm(f[i][j][k][g],f[i][j-1][k][g]);
					if(g<=a[j])
					cm(f[i][j][k][a[j]],f[i][j-1][k][g]+1);
				}
	for(int j=1;j<=n;++j)
		for(int i=j;i>=1;--i)
			for(int k=0;k<2;++k)
				for(int g=0;g<2;++g)
				{
					cm(fr[i][j][k][g],fr[i][j-1][k][g]);
					if(g>=a[j])
					cm(fr[i][j][k][a[j]],fr[i][j-1][k][g]+1);
				}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			for(int a=0;a<2;++a)
				for(int b=0;b<2;++b)
					for(int c=0;c<2;++c)
						for(int d=0;d<2;++d)
							ans=max(ans,fr[i][j][b][a]
							+f[1][i-1][c][a]+f[j+1][n][b][d]);
	printf("%d\n",ans);
}