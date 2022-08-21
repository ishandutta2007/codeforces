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
const int MOD=998244353;
int f[2][205][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	f[0][0][0]=1;
	int c=0;
	for(int i=1;i<=n;++i)
	{
		c^=1;
		memset(f[c],0,sizeof f[c]);
		//case1. norm
		int s=0,p=0;
		for(int j=0;j<=200;++j)
			(s+=f[c^1][j][0])%=MOD;
		for(int j=200;j>=1;--j)
		{
			if(j==a[i]||a[i]==-1)
				(f[c][j][0]+=s)%=MOD,
				(f[c][j][0]+=p)%=MOD;
			(p+=f[c^1][j][1])%=MOD;
		}
		//case2. better
		s=p=0;
		for(int j=1;j<=200;++j)
		{
			(s+=f[c^1][j-1][0])%=MOD;
			if(j==a[i]||a[i]==-1)
				(f[c][j][1]-=s)%=MOD;
		}
	}
	int ans=0;
	for(int i=1;i<=200;++i)
		(ans+=f[c][i][1])%=MOD,
		(ans+=f[c][i][0])%=MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}