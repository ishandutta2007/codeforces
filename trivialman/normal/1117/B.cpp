#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

LL n,m,k,a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	LL part = m/(k+1);
	//cout<<a[1]<<" "<<a[2]<<endl;
	cout<<(m-part)*a[1]+part*a[2]<<endl;
	return 0;
}