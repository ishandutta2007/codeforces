#include "bits/stdc++.h"
using namespace std;
int n,mx,sum,a;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a;
		mx=max(mx,a);
		sum+=a;
	}
	printf("%d\n",mx*n-sum);
	return 0;
}