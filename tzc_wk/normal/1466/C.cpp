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
const int MAXN=1e5;
int n;char s[MAXN+5];
int dp[MAXN+5][8];
void solve(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=0;i<2;i++) dp[1][i]=i;
	for(int i=2;i<8;i++) dp[1][i]=1e9;
	for(int i=2;i<=n;i++){
		for(int j=0;j<8;j++){
			dp[i][j]=1e9;bool flg=1;
			if(s[i]==s[i-1]&&!(j&1)&&!(j>>1&1)) flg=0;
			if(s[i]==s[i-2]&&!(j&1)&&!(j>>2&1)) flg=0;
			if(s[i-1]==s[i-2]&&!(j>>1&1)&&!(j>>2&1)) flg=0;
			if(flg){
				dp[i][j]=min(dp[i][j],dp[i-1][j>>1]+(j&1));
				dp[i][j]=min(dp[i][j],dp[i-1][4+(j>>1)]+(j&1));
			}
//			printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	int mn=1e9;
	for(int j=0;j<8;j++) mn=min(mn,dp[n][j]);
	printf("%d\n",mn);
}
int main(){
	int T;scanf("%d",&T);while(T--) solve();
	return 0;
}