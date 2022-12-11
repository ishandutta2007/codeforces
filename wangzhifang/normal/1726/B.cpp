#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_n=100000;
int a[max_n+1];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<n||(!(n&1)&&(m&1))){
		puts("No");
		return;
	}
	puts("Yes");
	if((n&1)){
		for(int i=1; i<n; ++i)
			printf("1 ");
		printf("%d\n",m-(n-1));
	}
	else{
		for(int i=n-2; i; --i)
			printf("1 ");
		printf("%d %d\n",(m-(n-2))/2,(m-(n-2))/2);
	}
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}