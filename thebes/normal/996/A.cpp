#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main(){
	scanf("%d",&n);
	while(n>=100) cnt++, n-=100;
	while(n>=20) cnt++, n-= 20;
	while(n>=10) cnt++, n-=10;
	while(n>=5) cnt++, n-=5;
	cnt += n;
	printf("%d\n",cnt);
	getchar(); getchar();
}