#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a,b,c,d,vis[1001],res[1001];

int main() {
	scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
	if(n==4 || m<n+1) {
		puts("-1");
		return 0;
	}
	
	res[0]=a; res[n-1]=b; res[1]=c; res[n-2]=d;

	int j=1;
	for(int i=2;i<n-2;i++) {
		while(j==a||j==b||j==c||j==d)j++;
		res[i]=j++;
	}
	for(int i=0;i<n;i++) printf("%d ",res[i]);
	puts("");
	printf("%d %d %d ",res[1],res[0],res[2]);
	for(int i=3;i<n-2;i++) printf("%d ",res[i]);
	printf("%d %d\n",res[n-1],res[n-2]);
	return 0;
}