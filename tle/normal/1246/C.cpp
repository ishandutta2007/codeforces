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
#include <assert.h>
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
int n,m;
const int MOD=1e9+7;
char g[2005][2005];
int Lg[2005][2005],Ug[2005][2005];
ll f[2005][2005][3],Lf[2005][2005][3],Uf[2005][2005][3];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",g[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Lg[i][j]=Lg[i][j-1]+(g[i][j]=='R'),
			Ug[i][j]=Ug[i-1][j]+(g[i][j]=='R');
	f[1][1][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			//w==1, r
			{
				int rp=Lg[i][m]-Lg[i][j];
				rp=m-j-rp;
				int l=1,r=j;
				while(l<r)
				{
					int g=(l+r)>>1;
					if(Lg[i][j]-Lg[i][g]>rp)
						l=g+1;
					else r=g;
				}
				for(int x=0;x<3;++x) if(x!=1)
					(f[i][j][1]+=Lf[i][j-1][x]-Lf[i][r-1][x])%=MOD;
			}
			//w==2, up
			{
				int rp=Ug[n][j]-Ug[i][j];
				rp=n-i-rp;
				int l=1,r=i;
				while(l<r)
				{
					int g=(l+r)>>1;
					if(Ug[i][j]-Ug[g][j]>rp)
						l=g+1;
					else r=g;
				}
				for(int x=0;x<3;++x) if(x!=2)
					(f[i][j][2]+=Uf[i-1][j][x]-Uf[r-1][j][x])%=MOD;
			}
			for(int x=0;x<3;++x)
			{
				Uf[i][j][x]=(Uf[i-1][j][x]+f[i][j][x])%MOD;
				Lf[i][j][x]=(Lf[i][j-1][x]+f[i][j][x])%MOD;
			}
		}
	}
	int sb=0;
	for(int x=0;x<3;++x)
		(sb+=f[n][m][x])%=MOD;
	sb=(sb%MOD+MOD)%MOD;
	cout<<sb<<"\n";
}