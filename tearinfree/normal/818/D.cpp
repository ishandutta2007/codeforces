#include <cstdio>

const int MAX=1e6;

int n,m,arr[1000001];

int main() {
	int val;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&val);
		if(val==m) arr[val]++;
		else if(arr[val]>=arr[m]) arr[val]++;
	}
	for(int i=1;i<=MAX;i++) {
		if(i!=m&&arr[i]>=arr[m]) {
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}