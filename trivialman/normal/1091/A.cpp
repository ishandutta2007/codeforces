#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int MOD = 998244353;
const int N = 100010;

int x,y,z,ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>x>>y>>z;
	ans = min(min(x+1,y),z-1);
	cout<<ans*3<<endl;
	return 0;
}