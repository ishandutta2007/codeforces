#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n, i, a[2];
int main(){
	for(scanf("%d",&n);i<n;i++)
		a[i%2]=(a[i%2]+a[(i+1)%2]+1)%mod;
	printf("%d\n",(a[0]+a[1])%mod);
	return 0;
}