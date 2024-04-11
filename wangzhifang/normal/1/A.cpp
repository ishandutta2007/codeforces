#include <cstdio>
using namespace std;
int main(){
	long long n,m,a;
	scanf("%I64d%I64d%I64d",& n,& m,& a);
	printf("%I64d\n",((n-1)/a+1)*((m-1)/a+1));
	return 0;
}