#include <bits/stdc++.h>
using namespace std;

int tot, a, b, N, i, x;

int main(){
	for(scanf("%d",&N);i<N;i++){
		scanf("%d",&x); tot += x;
		if(x%2) b ++;
		else  a ++;
	}
	printf("%d\n",(tot%2)?b:a);
	return 0;
}