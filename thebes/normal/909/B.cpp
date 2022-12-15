#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, x;
	scanf("%d",&N); x = N/2;
	if(N == 2) printf("2\n");
	else printf("%d\n",x*(x+1)/2+(N-x)*(N-x+1)/2);
	return 0;
}