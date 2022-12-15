#include <bits/stdc++.h>
using namespace std;

int N, S, i, j;
int main(){
	scanf("%d",&N);
	S = sqrt(N+0.0);
	for(i=N+1;i>=0;i--){
		for(j=S*i;j<min(N,S*i+S);j++)
			printf("%d ",j+1);
	}
	return 0;
}