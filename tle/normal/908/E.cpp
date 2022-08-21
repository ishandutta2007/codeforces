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
int n,m; ll hsh[2333],C[2333][2333],B[2333];
map<ll,int> cnt;
char str[2333];
const int MOD=1e9+7;
int main()
{
	for(int i=0;i<=2000;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	B[0]=B[1]=1;
	for(int i=1;i<=2000;++i)
		for(int j=0;j<=i;++j)
			(B[i+1]+=C[i][j]*B[j])%=MOD;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str);
		for(int j=0;str[j];++j)
			if(str[j]=='1') hsh[j]^=1LL<<i;
	}
	for(int i=0;i<m;++i) cnt[hsh[i]]++;
	ll ans=1;
	for(auto s:cnt) ans=ans*B[s.se]%MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}