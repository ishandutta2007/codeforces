#include <cstdio>

int n,arr[100][100];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		if(arr[i][j]==1) continue;
		bool flag=false;
		for(int a=0;a<n;a++) {
			for(int b=0;b<n;b++) {
				if(arr[i][a]+arr[b][j]==arr[i][j]) {
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	
	return 0;
}