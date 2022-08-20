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
int T,n;
char a[3333],b[3333];
ll f[2005][4005];
ll g[2005][4005];
const int MOD=1e9+7;
void sol() {
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=0;i<=n;++i)
		memset(f[i],0,sizeof f[i]),
		memset(g[i],0,sizeof g[i]);
	f[0][n]=0; g[0][n]=1;
	for(int i=1;i<=n;++i) {
		ll F,G;
		for(int j=0;j<=n+n;++j) if(G=g[i-1][j]) {
			F=f[i-1][j];
			for(int p='0';p<='1';++p) {
				if(isdigit(a[i])&&p!=a[i]) continue;
				for(int q='0';q<='1';++q) {
					if(isdigit(b[i])&&q!=b[i]) continue;
					int dt=0;
					if(p!=q) {
						dt+=((p^i)&1)*2-1;
					}
					(g[i][j+dt]+=G)%=MOD;
					(f[i][j+dt]+=F+abs(j-n)*G)%=MOD;
				}
			}
		}
	}
	ll ans=f[n][n];
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}