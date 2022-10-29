#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;

LL n,b,p[50],k[50],num;

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	cin>>n>>b;
	for(LL i=2;i*i<=b;++i){
		if(b%i==0){
			p[++num] = i;
			while(b%i==0) b/=i,++k[num];
		}
	}
	if(b>1){p[++num]=b;k[num]=1;}
	LL ans = 5e18;
	rep(i,1,num){
		LL x = p[i], y = n, cnt = 0;
		for(;y;y/=x)cnt += y/x;
		ans = min(ans, cnt/k[i]);
	}
	cout<<ans<<endl;
	return 0;
}