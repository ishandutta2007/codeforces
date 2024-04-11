#include <bits/stdc++.h>
using namespace std;

int N, K, i;

int main(){
	scanf("%d%d",&N,&K);
	for(i=1;i<=K;i++) printf("%c",'a'+i-1);
	for(;i<=N;i++) printf("%c",(i%2)?'a':'b');
	return 0;
}