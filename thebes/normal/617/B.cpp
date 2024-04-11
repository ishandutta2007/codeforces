#include <bits/stdc++.h>
using namespace std;

int n, arr[101], i, j, last;
long long ans=1;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=n;i++){
		if(arr[i]==1){
			if(last) ans *= (i-last);
			last = i;
		}
	}
	printf("%lld\n",(last)?ans:0);
	return 0;
}