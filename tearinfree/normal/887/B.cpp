#include <bits/stdc++.h>
using namespace std;

int n,arr[3][6],cnt[1000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<6;j++) scanf("%d",&arr[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<6;j++) cnt[arr[i][j]]=1;
	if(n>=2) {
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int a=0;a<6;a++) for(int b=0;b<6;b++) {
			if(i==j) continue;
			if(arr[i][a]==0) continue;
			cnt[arr[i][a]*10+arr[j][b]]=1;
		}
	}
	if(n>=3) {
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) {
			if(i==j || j==k || k==i) continue;
			for(int a=0;a<6;a++) {
				if(arr[i][a]==0) continue;
				for(int b=0;b<6;b++) for(int c=0;c<6;c++) {
					cnt[arr[i][a]*100+arr[j][b]*10+arr[k][c]]=1;
				}
			}
		}
	}

	int j=1;
	while(j<1000 && cnt[j]) j++;
	printf("%d\n",j-1);

	return 0;
}