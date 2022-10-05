#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN=1e5;
const int MAXC=1e4;
const int INF=0x3f3f3f3f;
int n,m,f[MAXN+5],siz[MAXN+5],k=0;
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
void merge(int x,int y){
	x=find(x);y=find(y);if(x==y) return;
	f[x]=y;siz[y]+=siz[x];
}
int cnt[MAXN+5],w[MAXC+5],v[MAXC+5],dp[MAXN+5];
bool check(int x){
	bool flg=1;
	while(x) flg&=(x%10==4||x%10==7),x/=10;
	return flg;\
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) siz[i]=1;
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),merge(u,v);
	for(int i=1;i<=n;i++) if(find(i)==i) cnt[siz[i]]++;
	for(int i=1;i<=n;i++) if(cnt[i]){
		int cur=1,tot=0;
		while(tot+cur<=cnt[i]) w[++k]=i*cur,v[k]=cur,tot+=cur,cur<<=1;
		if(tot!=cnt[i]) w[++k]=i*(cnt[i]-tot),v[k]=cnt[i]-tot;
	} memset(dp,63,sizeof(dp));dp[0]=0;
//	for(int i=1;i<=k;i++) printf("%d %d\n",w[i],v[i]);
	for(int i=1;i<=k;i++) for(int j=n;j>=w[i];j--) chkmin(dp[j],dp[j-w[i]]+v[i]);
	int res=INF;for(int i=1;i<=n;i++) if(check(i)) chkmin(res,dp[i]);
	printf("%d\n",(res==INF)?-1:(res-1));
	return 0;
}