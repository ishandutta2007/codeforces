#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(time(0));

int n, ma, x, y;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	ma = y = 0;
	rep(i,1,n){
		scanf("%d",&x);
		if(x>=0) y = (ma += x);
		else y = ma + x;
		printf("%d ",y);
	}
	return 0;
}