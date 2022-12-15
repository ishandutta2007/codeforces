#include <bits/stdc++.h>
using namespace std;

int N, lol, i, x;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&x), lol|=x;
	printf("%s\n",(lol)?"HARD":"EASY");
	return 0;
}