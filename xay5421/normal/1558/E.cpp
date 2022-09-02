// author: xay5421
// created: Wed Aug 25 15:39:45 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=1005;
int T,n,m,in[N],vis[N],a[N],b[N];
vector<int>e[N];
LL cur;
bool dfs(int k1,int k2){
	if(vis[k1]||in[k1])return 1;
	if(cur<a[k1])return 0;
	vis[k1]=1;
	cur+=b[k1];
	for(int x:e[k1])if(x!=k2&&dfs(x,k1)){vis[k1]=0,in[k1]=1;return 1;}
	cur-=b[k1];
	vis[k1]=0;
	return 0;
}
bool chk(int mid){
	rep(i,1,n)in[i]=0;
	in[1]=1,cur=mid;
	while(1){
		rep(i,1,n)if(in[i]){
			for(auto x:e[i])if(!in[x]){
				if(dfs(x,i)){
					goto qaq;
				}
			}
		}
		return 0;
		qaq:;
		if(count(in+1,in+1+n,1)==n)return 1;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)e[i].clear();
		rep(i,2,n)scanf("%d",&a[i]);
		rep(i,2,n)scanf("%d",&b[i]);
		rep(i,1,m){
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			e[k1].push_back(k2),e[k2].push_back(k1);
		}
		int l=0,r=1000000000,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			//D("mid=%d\n",mid);
			if(chk(mid)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}