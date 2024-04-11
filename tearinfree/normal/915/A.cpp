#include <cstdio>


int main() {
	int n,k,val,mx=1e9;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) {
		scanf("%d",&val);
		if(k%val==0 && mx>k/val) mx=k/val;
	}
	printf("%d\n",mx);
}