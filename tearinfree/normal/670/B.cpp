#include <bits/stdc++.h>
using namespace std;

int n,k,arr[100001];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	
	long long sum=0;
	for(int i=1;i<=n;i++) {
		if(sum+i>=k) {
			k-=sum;
			printf("%d\n",arr[k]);
			return 0;
		}
		sum+=i;
	}

	return 0;
}