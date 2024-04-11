/*
Contest: - 
Problem: Codeforces 288E 
Author: tzc_wk
Time: 2020.10.12
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
const ll MOD=1e9+7;
char s[100005];int n;
struct data{
	ll sqr,cnt,sum;
	data(ll _sqr=0,ll _sum=0,ll _cnt=0){
		sqr=_sqr;sum=_sum;cnt=_cnt;
	}
} dp[100005][2];
ll pw[200005],seven[100005],four[100005];
inline data upd4(data p){
	return data(
	(p.sqr*100ll+p.sum*80ll+p.cnt*16ll)%MOD,
	(p.sum*10ll+p.cnt*4ll)%MOD,(p.cnt));
}
inline data upd7(data p){
	return data(
	(p.sqr*100ll+p.sum*140ll+p.cnt*49ll)%MOD,
	(p.sum*10ll+p.cnt*7ll)%MOD,(p.cnt));
}
inline void add(data &x,data y){
	x.sqr+=y.sqr;if(x.sqr>=MOD) x.sqr-=MOD;
	x.sum+=y.sum;if(x.sum>=MOD) x.sum-=MOD;
	x.cnt+=y.cnt;if(x.cnt>=MOD) x.cnt-=MOD;
}
inline ll get(data x,ll k);
inline ll calc(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=data(0,0,0);
	dp[0][1]=data(0,0,1);
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i][1]=data(0,0,0);
		if(s[i]=='4'){
			add(dp[i][0],upd4(dp[i-1][0]));
			add(dp[i][0],upd7(dp[i-1][0]));
			add(dp[i][1],upd4(dp[i-1][1]));
		}
		else{
			add(dp[i][0],upd4(dp[i-1][0]));
			add(dp[i][0],upd4(dp[i-1][1]));
			add(dp[i][0],upd7(dp[i-1][0]));
			add(dp[i][1],upd7(dp[i-1][1]));
		}
//		printf("%lld %lld %lld\n",dp[i][0].sqr,dp[i][0].sum,dp[i][0].cnt);
//		printf("%lld %lld %lld\n",dp[i][1].sqr,dp[i][1].sum,dp[i][1].cnt);
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(s[i+1]=='4'){
			ans=(ans+get(dp[i][0],n-i-1))%MOD;
		} else{
			ans=(ans+get(dp[i][0],n-i-1))%MOD;
			ans=(ans+get(dp[i][1],n-i-1))%MOD;
		}
	}
//	printf("%lld\n",ans);
	return ans;
}
int main(){
	pw[0]=1;for(int i=1;i<=200002;i++) pw[i]=pw[i-1]*10%MOD;
	for(int i=1;i<=100000;i++) seven[i]=(seven[i-1]*10+7)%MOD;
	for(int i=1;i<=100000;i++) four[i]=(four[i-1]*10+4)%MOD;
	ll L=calc(),R=calc();
	printf("%lld\n",(R-L+MOD)%MOD);
	return 0;
}
/*
474447477477774747744777777
->
474447477477774747747444444

((10x+4)*10^k+77777...7)*((10x+7)*10^k+4444...4)
=7777...7*4444...4+7777...7*(10x+7)*10^k
+4444...4*(10x+4)*10^k+(10x+4)*(10x+7)*10^{2k}
=7777...7*4444...4*cnt+7777...7*10^{k+1}*sum_x+7777...7*7*10^k*cnt
+4444...4*10^{k+1}*sum_x+4444...4*4*10^k*cnt
+10^{2k+2}*sqr_x+110*10^{2k}*sum_x+28*10^{2k}*cnt
*/
inline ll get(data x,ll k){
//	printf("%d %d %d\n",x.sqr,x.sum,x.cnt);
	return (seven[k]*four[k]%MOD*x.cnt%MOD+seven[k]*pw[k+1]%MOD*x.sum%MOD+
	seven[k]*7%MOD*pw[k]%MOD*x.cnt%MOD+four[k]*pw[k+1]%MOD*x.sum%MOD+
	four[k]*4%MOD*pw[k]%MOD*x.cnt%MOD+pw[(k<<1)+2]*x.sqr%MOD+
	110*pw[k<<1]%MOD*x.sum%MOD+28*pw[k<<1]%MOD*x.cnt%MOD)%MOD;
}