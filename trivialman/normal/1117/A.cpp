#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

int n,big=0,a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i],big=max(big,a[i]);
	int ans=0, tmp=0;
	rep(i,1,n)if(a[i]==big){
		++tmp;
		ans=max(ans,tmp);
	}else tmp=0;
	cout<<ans<<endl;
	return 0;
}