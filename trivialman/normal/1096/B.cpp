#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

LL n;
string s;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	cin>>s;
	LL l = 0, r = n - 1;
	while(s[l]==s[0])++l;
	while(s[r]==s[n-1])--r;
	LL ans = l + (n-r);
	if(s[0]==s[n-1])ans+=l*(n-r-1);
	cout<<ans%MOD<<endl;
	return 0;
}