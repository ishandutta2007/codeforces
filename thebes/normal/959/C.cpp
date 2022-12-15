#include <bits/stdc++.h>
using namespace std;

int N, i;

int main(){
	scanf("%d",&N);
	if(N<6) printf("-1\n");
	else{
		for(i=0;i<3;i++)
			printf("1 %d\n",i+2);
		for(;i<N-1;i++)
			printf("2 %d\n",i+2);
	}
	for(i=1;i<N;i++)
		printf("%d %d\n",i,i+1);
	return 0;
}