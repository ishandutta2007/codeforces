#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

int t,n;
string s;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		int x1,x2;
		for(x1=0;x1<n&&s[x1]=='<';++x1);
		for(x2=n-1;x2&&s[x2]=='>';--x2);
		cout<<min(x1,n-1-x2)<<endl;
	}
	return 0;
}