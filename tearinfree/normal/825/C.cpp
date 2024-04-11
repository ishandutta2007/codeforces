#include <bits/stdc++.h>

int n,k;
int arr[1000];

int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",arr+i);
	std::sort(arr,arr+n);
	
	int i=0,cnt=0;
	while(i<n) {
		while(i<n&&k*2>=arr[i]) k=std::max(k,arr[i]),i++;
		if(i==n) break;
		
		while(k*2<arr[i]) k=k*2,cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}