#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 300010;

int n,l,r,a[N],b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i];
	l=1;r=n;
	for(;a[l]==a[n];++l);
	for(;a[1]==a[r];--r);
	cout<<max(n-l,r-1)<<endl;
	return 0;
}