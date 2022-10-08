#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n,l,r,sz[2333],ans;
void getsize(ll n,int dep){
	if (n == 1 || n == 0) sz[dep] = 1;
	else getsize (n>>1,dep+1), sz[dep] = 1 + (sz[dep+1] << 1);
}
void Search(ll n,ll l,ll r,int dep){
	if (n == 1 || n == 0) {ans += n; return;}
	ll mid = (sz[dep] >> 1) + 1;
	if (l <= mid && mid <= r) ans += n & 1;
	if (l < mid) Search (n>>1,l,min(r,mid-1),dep+1);
	if (r > mid) Search (n>>1,max(1ll,l-mid),r-mid,dep+1);
}
int main(){
	cin>>n>>l>>r;
	getsize(n,0);
	Search(n,l,r,0);
	cout<<ans<<endl;
	return 0;
}