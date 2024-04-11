// author: xay5421
// created: Thu Mar 11 13:51:56 2021
#include<bits/stdc++.h>
#define popcnt(x) __builtin_popcount(x)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
int n,mp[20];
LL dp[20][(1<<18)+5],g[20][(1<<18)+5],f[(1<<17)+5];
void fwt_or(LL*a,int n){
	for(int i=1;i<(1<<n);i<<=1)for(int j=0;j<(1<<n);j+=i<<1)for(int k=0;k<i;++k)a[i+j+k]+=a[j+k];
}
void ifwt_and(LL*a,int n){
	for(int i=1;i<(1<<n);i<<=1)for(int j=0;j<(1<<n);j+=i<<1)for(int k=0;k<i;++k)a[j+k]-=a[i+j+k];
}
void init(){
	rep(i,0,n-1)dp[i][1<<i]=1;
	rep(i,1,(1<<n)-1){
		rep(j,0,n-1)if(i>>j&1){
			rep(k,0,n-1)if(~i>>k&1)if(mp[j]>>k&1){
				dp[k][i^(1<<k)]+=dp[j][i];
			}
		}
	}
	rep(i,0,n-1)rep(j,0,(1<<n)-1)g[popcnt(j)][j]+=dp[i][j];
	rep(i,0,n-1)fwt_or(g[i],n);
}
LL A[20][(1<<18)+5];
void dot(LL*a,LL*b,LL*c){
	rep(i,0,(1<<n)-1)c[i]=a[i]*b[i];
}
map<vector<int>,LL>res;
vector<int>now;
void dfs(int k1,int k2,int k3){
	if(!k3){
		LL x=0;
		rep(i,0,(1<<n)-1)x+=A[k1][i]*(popcnt((1<<n)-1-i)&1?-1:1);
		res[now]=x;
		return;
	}
	rep(i,k2,k3)dot(A[k1],g[i],A[k1+1]),now.push_back(i),dfs(k1+1,i,k3-i),now.pop_back();
}
int main(){
	scanf("%d",&n);
	rep(i,0,n-1){
		rep(j,0,n-1){
			int c;
			while(!isdigit(c=getchar()));
			if(c&1)mp[i]^=1<<j;
		}
	}
	init();
	rep(i,0,(1<<n)-1)A[0][i]=1;
	dfs(0,1,n);
	auto calc=[&](int i){
		vector<int>cur;
		for(int l=0,r;l<n;l=r+1){
			r=l;
			while(r<n&&(i>>r&1))++r;
			cur.push_back(r-l+1);
		}
		sort(cur.begin(),cur.end());
		return res[cur];
	};
	rep(i,0,(1<<(n-1))-1){
		f[i]=calc(i);
	}
	ifwt_and(f,n-1);
	rep(i,0,(1<<(n-1))-1)printf("%lld ",f[i]);
	return 0;
}