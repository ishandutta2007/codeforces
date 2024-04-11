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

int n, x[N], y[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",x+i,y+i);
	if(n%2){
		printf("NO\n");
		return 0;
	}
	
	x[n+1] = x[1], y[n+1] = y[1];
	int m = n/2;
	rep(i,1,m){
		if(x[i+1]-x[i] != -x[i+m+1]+x[i+m] || y[i+1]-y[i] != -y[i+m+1]+y[i+m]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}