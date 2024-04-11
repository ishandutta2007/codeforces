#include <stdio.h>

bool vis[1000100];

int main()
{
	for(int i=2;i<=1000;i++) {
		if(!vis[i]) {
			for(int j=i*i;j<=1000000;j+=i) {
				vis[j]=true;
			}
		}
	}

	int n;
	scanf("%d",&n);
	for(int i=1;i<=1000;i++) {
		if(vis[n*i+1]) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}