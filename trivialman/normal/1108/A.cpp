#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

int n,l1,r1,l2,r2,l,r;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n){
		cin>>l1>>r1>>l2>>r2;
		if(l1<r2)cout<<l1<<" "<<r2<<endl;
		else cout<<r1<<" "<<l2<<endl;
	}
	return 0;
}