#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;
int n, cnt, i, arr[205];
int main(){
	for(scanf("%d",&n),i=1;i<=2*n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=2*n;i+=2){
		for(int j=2*n-1;j>=i+1;j--){
			if(arr[j+1]==arr[i]){
				swap(arr[j], arr[j+1]);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	getchar(); getchar();
}