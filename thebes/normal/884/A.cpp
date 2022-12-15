#include <bits/stdc++.h>
using namespace std;

int N, T, i, x;

int main(){
	for(scanf("%d%d",&N,&T),i=1;i<=N;i++){
		scanf("%d",&x);
		T -= 86400-x;
		if(T <= 0){printf("%d\n",i);return 0;}
	}
}