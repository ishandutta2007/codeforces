#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

bool l(int n){
	bool ret = 1;
	while(n){
		if(n%10!=4&&n%10!=7) ret=0;
		n /= 10;
	}
	return ret;
}

int main(){
	int n; scanf("%d",&n);
	int fnd = 0;
	for(int i=1;i<=n;i++){
		if(n%i==0&&l(i)) fnd=1;
	}
	printf("%s\n",(fnd)?"YES":"NO");
	return 0;
}