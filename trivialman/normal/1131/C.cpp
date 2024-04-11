#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;

int n,a[110],b[110];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n/2){
		b[n/2+i] = a[i*2-1];
		b[n/2-i+1] = a[i*2];
	}
	if(n%2)b[n] = a[n];
	rep(i,1,n)cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}