#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
LL a[N],b[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n/2)scanf("%lld",&b[i]);
	LL t = b[1];
	rep(i,1,n/2){
		t = min(t,b[i]);
		a[n+1-i] = t;
		a[i] = b[i] - t;
		t = min(t,b[i+1]-a[i]);
	}
	rep(i,1,n)printf("%lld ",a[i]);
	return 0;
}