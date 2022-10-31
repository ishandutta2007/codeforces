#include <bits/stdc++.h>
using namespace std;

int n,k,arr[100001];

int sum(int idx) {
	int s=0;
	for(int j=0;j<3;j++) if(arr[idx+j]==-1) ++s;
	return s;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",arr+i);
		for(int i=0;i<n;i++) arr[i] = (arr[i]==k ? 0 : arr[i]>k ? 1 : -1);
		
		int chk = 0;
		for(int i=0;i<n;i++) if(!arr[i]) {
			chk=1;
			break;
		}
		if(!chk) {
			puts("no");
			continue;
		}

		if(n==1) {
			puts(!arr[0] ? "yes" : "no");
		} else {
			bool ans = false;
			for(int i=0;i<n;i++) {
				if(i<n-1 && arr[i]!=-1 && arr[i+1]!=-1) {
					ans = true;
					break;
				} else if(i<n-2 && sum(i)<=1) {
					ans = true;
					break;
				}
			}
			puts(ans ? "yes" : "no");
		}
	}
	return 0;
}