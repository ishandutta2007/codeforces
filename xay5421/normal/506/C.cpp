#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define D(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long LL;
const int N=100005;
int n,m,K,p,h[N],a[N],f[N];
bool chk(LL mid){
	memset(f,0,sizeof(f));
	set<pair<LL,int> >S;
	rep(i,1,n)if(mid-1LL*a[i]*m<h[i])S.insert({mid/a[i],i});
	rep(i,1,m)rep(j,1,K){
		if(S.empty())return 1;
		auto now=*S.begin();S.erase(S.begin());
		if(now.fi<i)return 0;
		++f[now.se];
		if(mid-1LL*a[now.se]*m+1LL*f[now.se]*p<h[now.se]){
			S.insert({(mid+1LL*f[now.se]*p)/a[now.se],now.se});
		}
	}
	return S.empty();
}
int main(){
	scanf("%d%d%d%d",&n,&m,&K,&p);
	rep(i,1,n){
		scanf("%d%d",&h[i],&a[i]);
	}
	LL l=0,r=1e13,ans=0;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}