#include <bits/stdc++.h>
using namespace std;

int n,arr[300001],cnt[300001];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	
	int j=n;
	printf("1 ");
	for(int i=1;i<=n;i++) {
		cnt[arr[i]]=1;
		while(j>0 && cnt[j])j--;
		printf("%d ",i-(n-j)+1);
	}

	return 0;
}