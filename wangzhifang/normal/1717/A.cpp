#include <cstdio>
using namespace std;
void test(){
	int n;
	scanf("%d",&n);
	printf("%d\n",n+n/2*2+n/3*2);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}