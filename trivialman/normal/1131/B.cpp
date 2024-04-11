#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 10010;

int n,a[N],b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)scanf("%d%d",a+i,b+i);
	a[0] = b[0] = 0;
	int ans = 0;
	rep(i,1,n){
		ans += max(0, min(a[i], b[i]) - max(a[i-1], b[i-1]) + 1);
		if(a[i]==b[i])--ans;
	}
	if(a[n]==b[n])++ans;
	cout<<ans<<endl;
	return 0;
}