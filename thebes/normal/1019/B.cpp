#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int x, y, lo, hi, n, a, b;
int qu(int w){
	printf("? %d\n",w);
	fflush(stdout);
	int r; cin>>r; return r;
}
void ans(int r){
	printf("! %d\n",r);
	fflush(stdout);
}
int main(){
	scanf("%d",&n);
	if(n%4){
		ans(-1);
		return 0;
	}
	lo = 1; hi = n/2;
	a = qu(1); b = qu(1+n/2);
	if(a == b){
		ans(1);
		return 0;
	}
	while(lo < hi){
		int m = lo+hi>>1;
		x = qu(m), y = qu(m+n/2);
		if(x == y){
			ans(m);
			return 0;
		}
		if((x>y)^(a>b)) hi=m;
		else lo=m+1;
	}
	ans(lo);
	return 0;
}