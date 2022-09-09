#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int mul(int x,int y){return (ll)x*y%mod;}
template<typename...A>int mul(int x,A...args){return (ll)x*mul(args...)%mod;}
int pw(int x,ll k){
	if(k<0)return 0;
	int ans=1;
	for(;k;k>>=1,x=mul(x,x))if(k&1)ans=mul(ans,x);
	return ans;
}
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
void ckadd(int&x,int y){x=add(x,y);}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
void cksub(int&x,int y){x=sub(x,y);}
const int N=100050;
ll cnt[N];
int dp[N];
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<=n;i++){
		int x,f;scanf("%i %i",&x,&f);
		cnt[x]+=f;
	}
	for(int i=N-1;i>=1;i--){
		ll c=0;int s=0;
		for(int j=i;j<N;j+=i){
			c+=cnt[j];
			ckadd(s,mul(cnt[j]%mod,j));
		}
		int p2=pw(2,c-2),p3=pw(2,c-3);
		for(int j=i;j<N;j+=i){
			if(c>1)
				ckadd(dp[i],mul(cnt[j],j,j,(c-1)%mod,p2)),
				ckadd(dp[i],mul(cnt[j],j,sub(s,j),p2));
			if(c>2)
				ckadd(dp[i],mul(cnt[j],j,sub(s,j),(c-2)%mod,p3));
		}
		for(int j=i*2;j<N;j+=i)cksub(dp[i],dp[j]);
	}
	printf("%i\n",dp[1]);
	return 0;
}