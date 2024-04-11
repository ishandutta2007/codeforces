#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 1004;
int arr[MN], n, w, i, a, b, tot;

int main(){
	for(scanf("%d%d",&n,&w),i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		tot += arr[i];
		a = max(tot, a);
		b = min(tot, b);
	}
	printf("%d\n",max(0,w-a+b+1));
	return 0;
}