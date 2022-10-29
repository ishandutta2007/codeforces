#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

LL n,m,ta,tb,k;
LL a[N],b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>ta>>tb>>k;
	rep(i,1,n)cin>>a[i];
	rep(i,1,m)cin>>b[i];
	if(k>=min(n,m)){
		cout<<"-1\n";
		return 0;
	}
	LL ans=-1;
	rep(i,0,k){
		int x1 = lower_bound(b+1,b+m+1,a[i+1]+ta) - b;
		if(x1+k-i>m){
			ans=-1;
			break;
		}
		ans = max(ans, b[x1+k-i]+tb);
		//cout<<i<<" "<<x1<<" "<<b[x1+k-i]+tb<<endl;
	}
	cout<<ans<<endl; 
	return 0;
}