#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXK=5000;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,k,s[MAXK+5][MAXK+5];
int main(){
	scanf("%d%d",&n,&k);s[0][0]=1;
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j]%MOD)%MOD;
	int mul=1,dbi=1,ans=0;
	for(int i=1;i<=min(n,k);i++){
		mul=1ll*mul*i%MOD;dbi=1ll*dbi*(n-i+1)%MOD*qpow(i,MOD-2)%MOD;
		ans=(ans+1ll*s[k][i]*mul%MOD*dbi%MOD*qpow(2,n-i)%MOD)%MOD;
	} printf("%d\n",ans);
	return 0;
}