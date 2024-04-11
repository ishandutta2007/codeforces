// author: xay5421
// created: Tue Oct 26 18:11:20 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int TT=998244353,P=1e9+7,B=1000000;
LL n;
LL cnt;
vector<int>v[10];
LL sum[10];
LL norm(LL x){
	x%=TT;
	if(x<0)return x+TT;
	return x;
}
void dfs1(int k1,int k2){
	++cnt;
	v[k1].pb(norm(cnt-k2));
	(sum[k1]+=v[k1].back())%=P;
	if(k1>=6)return;
	rep(i,0,9){
		dfs1(k1+1,k2*10+i);
	}
}
int ans;
void dfs2(int k1,LL k2){
	if(k2>n)return;
	if(k1>=1){
		if(k2*B>n/10&&k2*B+B-1<=n){ // (cnt-v*10^{lg(v')})+(cnt'-v')
			LL pw=1;
			rep(i,0,6){
				if(i)pw*=10;
				int now=norm(cnt-k2*pw);
				int pos=lower_bound(v[i].begin(),v[i].end(),TT-now)-v[i].begin();
				ans=(ans+sum[i]+1LL*now*SZ(v[i])-1LL*(SZ(v[i])-pos)*TT)%P;
			}
			rep(i,0,6)cnt+=SZ(v[i]);
			return;
		}
		++cnt,(ans+=norm(cnt-k2))%=P;
	}
	rep(i,!k1,9)dfs2(k1+1,k2*10+i);
}
int main(){
	scanf("%lld",&n);
	dfs1(0,0);
	rep(i,0,6)sort(v[i].begin(),v[i].end());
	cnt=0,dfs2(0,0);
	printf("%d\n",ans);
	return 0;
}