#include <bits/stdc++.h>
using namespace std;

int N, i, a, b, c, d, tmp, cnt;
int main(){
	scanf("%d%d%d%d%d",&N,&a,&b,&c,&d);
	tmp = a + b + c + d;
	for(i=2;i<=N;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a+b+c+d>tmp) cnt++;
	}
	printf("%d\n",cnt+1);
	return 0;
}