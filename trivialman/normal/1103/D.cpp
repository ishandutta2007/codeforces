#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL INF = 1e17;
const int N = 1000010;

struct dat{
	LL u,e;
}a[N];
LL n,k,num=0;
LL dp[12][1<<11], dp1[12][1<<11];
LL had1[1<<11], part[1<<11], p[20], pk[20];

map<LL, int> had;

LL GCD(LL x, LL y){
	LL r;
	while(x) r = y % x, y = x, x = r;
	return y;
}

bool cmp(dat x,dat y){return x.e<y.e;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%lld%lld",&n,&k);
	LL gcd = 0;
	rep(i,1,n){
		scanf("%lld",&a[i].u);
		gcd = GCD(gcd, a[i].u);
	}
	if(gcd==1){
		puts("0");
		return 0;
	}
	
	rep(i,1,n)scanf("%lld",&a[i].e);
	sort(a+1,a+n+1,cmp);
	for(LL i=2;i*i<=gcd;++i) if(gcd%i==0)
		for(p[++num]=i; gcd%i==0; gcd/=i);
	if(gcd>1)p[++num]=gcd;
	
	rep(i,0,num)rep(j,0,(1<<num)-1)dp[i][j]=j==0?0:INF;
	
	rep(i,1,n){
		LL newu = 1;
		rep(j,1,num)
			for(pk[j]=1; a[i].u%p[j]==0; a[i].u/=p[j]) newu*=p[j], pk[j]*=p[j];
		++had[newu];
		if(had[newu]>num)continue;
		
		memcpy(dp1,dp,sizeof(dp));
		part[0] = 1;
		rep(digit,0,num-1){
			rep(j,1<<digit,(1<<digit+1)-1){
				part[j] = part[j-(1<<digit)] * pk[digit+1];
				if(part[j]>k || had1[j]>=num)continue;
				++had1[j];
				rep(d1,0,num-1) rep(l,0,(1<<num)-1)
					dp[d1+1][l|j] = min(dp[d1+1][l|j], dp1[d1][l]+a[i].e);
			}
		}
	}
	LL ans = INF;
	rep(i,1,num) ans = min(ans, dp[i][(1<<num)-1] * i);
	cout<<(ans==INF?-1:ans)<<endl;
	return 0;
}