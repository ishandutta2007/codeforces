#include <cstdio>
#include <algorithm>

int n,arr[1000],k;
int main() {
	scanf("%d%d",&n,&k);
	
	int sum=0;
	int sv=0;
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		arr[i]+=sv;
		sv=0;
		if(arr[i]>8){
			sv=arr[i]-8;
			arr[i]=8;
		}
		sum+=arr[i];
		if(sum>=k) {
			printf("%d\n",i+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}