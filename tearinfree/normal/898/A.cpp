#include <cstdio>
int main() {
	int n;
	scanf("%d",&n);
	
	int v=n%10,c=n/10;
	if(v>5) c++;
	printf("%d\n",c*10);
	return 0;
}