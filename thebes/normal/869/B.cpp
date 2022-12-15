#include <iostream>
using namespace std;

long long lst=1, i, x, y;

int main(){
	scanf("%I64d%I64d",&x,&y);
	for(i=x+1;i<=y&&lst;i++)
		lst *= (i%10);
	printf("%I64d\n",lst%10);
	return 0;
}