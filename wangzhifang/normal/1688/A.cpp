#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void test(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(n&(n-1))?n&(-n):(n==1?3:(n+1)));
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}