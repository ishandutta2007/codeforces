#include <bits/stdc++.h>
using namespace std;

const int MN = 5e5 + 5;
int p[MN], N, i; long long b, x, sol;
char arr[MN];

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&p[i]);
	scanf(" %s",arr);
	for(i=0;i<N;i++){
		if(arr[i]=='B') b+=p[i+1];
	}
	sol = b; x = b;
	for(i=1;i<=N;i++){
		if(arr[i-1]=='A') b+=p[i];
		else b-=p[i];
		sol = max(sol, b);
	}
	b = x;
	for(i=N;i>=1;i--){
		if(arr[i-1]=='A') b+=p[i];
		else b-=p[i];
		sol = max(sol, b);
	}
	printf("%lld\n",sol);
	return 0;
}