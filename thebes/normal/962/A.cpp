#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int N, i, arr[MN], x, tot;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]),tot+=arr[i];
	for(i=1;i<=N;i++){
		x += arr[i];
		if(x>=ceil(tot/2.0))
		{printf("%d\n",i); break;}
	}
	return 0;
}