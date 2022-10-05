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
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MAXM=2000+5;
const int MAXMSK=60000;
const int MAXN=12+3;
struct node{
	int v,id;
	friend bool operator <(node x,node y){
		return x.v>y.v;
	}
} x[MAXM];
int n,m,a[MAXN][MAXM],dp[MAXN][MAXMSK],s[MAXN][MAXMSK];
void solve(){
	memset(a,0,sizeof(a));memset(dp,0,sizeof(dp));
	memset(s,0,sizeof(s));
	for(int i=1;i<=m;i++) x[i].v=x[i].id=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) x[i].id=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]),x[j].v=max(x[j].v,a[i][j]);
	sort(x+1,x+m+1);
	for(int i=1;i<=min(n,m);i++){
		for(int j=0;j<(1<<n);j++){
			for(int l=1;l<=n;l++){
				if(j>>(l-1)&1) s[i][j]+=a[l][x[i].id];
			}
		}
	}
	for(int i=1;i<=min(n,m);i++) for(int j=0;j<(1<<n);j++)
		for(int k=0;k<n;k++) s[i][j]=max(s[i][j],s[i][((j>>k)|(j<<(n-k)))&((1<<n)-1)]);
	for(int i=1;i<=min(n,m);i++) for(int j=0;j<(1<<n);j++){
		dp[i][j]=dp[i-1][j];
		for(int k=j;k;k=(k-1)&j) dp[i][j]=max(dp[i][j],dp[i-1][j^k]+s[i][k]);
	}
	printf("%d\n",dp[min(n,m)][(1<<n)-1]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}