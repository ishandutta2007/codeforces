#include <bits/stdc++.h>
using namespace std;

int B, C, N, i, x;

int main(){
	for(scanf("%d",&N);i<N;i++){
		scanf("%d",&x);
		if(x>0) B += x;
		else C += x;
	}
	printf("%d\n",B-C);
	return 0;
}