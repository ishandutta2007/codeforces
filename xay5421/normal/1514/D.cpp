// author: xay5421
// created: Wed Apr 21 13:51:27 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n,Q,a[300005];
vector<int>v[300005];
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int calc(int l,int r,int x){return upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);}
int main(){
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&a[i]),v[a[i]].push_back(i);
	rep(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=1;
		rep(_,1,40){
			ans=max(ans,calc(l,r,a[rng()%(r-l+1)+l])*2-(r-l+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}