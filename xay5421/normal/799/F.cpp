// author: xay5421
// created: Fri Apr 23 18:58:54 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N=200005;
mt19937_64 rng(233);
int n,m,vis[N];
ULL key[N],sum[N],ans;
map<ULL,LL>mp1,mp2;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int l,r;
		scanf("%d%d",&l,&r);
		key[i]=rng();
		sum[l+1]^=key[i],sum[r+1]^=key[i];
		++vis[l],--vis[r+1];
	}
	rep(i,1,m)sum[i]^=sum[i-1],vis[i]+=vis[i-1];
	ULL cur=0;
	rep(i,1,m){
		cur^=sum[i];
		++mp1[cur];
		mp2[cur]+=i-1;
		ans+=1LL*i*mp1[cur]-mp2[cur];
	}
	for(int i=1,j;i<=m;i=j){
		j=i+1;
		if(vis[i])continue;
		while(j<=m&&!vis[j])++j;
		int len=j-i;
		rep(k,1,len){
			ans-=1LL*k*(len-k+1);
		}
	}
	printf("%llu\n",ans);
	return 0;
}