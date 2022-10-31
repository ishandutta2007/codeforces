#include <cstdio>

int n=4,arr[4][4];

int main() {
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<n-1;j++) {
		if(arr[i][j]) {
			if(j==0) {
				if(arr[(i+3)%n][3]||arr[i][3]) {
					printf("YES\n");
					return 0;
				}
			}
			else if(j==1) {
				if(arr[(i+2)%n][3]||arr[i][3]) {
					printf("YES\n");
					return 0;
				}
			}
			else {
				if(arr[(i+1)%n][3]||arr[i][3]) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}