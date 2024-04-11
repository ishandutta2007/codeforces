#include <bits/stdc++.h>
using namespace std;

int a, b, c, n, f[1001];

int main(){
	scanf("%d",&n);
	b=1; c = a+b;
	while(c <= n){
		f[c] = 1;
		a = b; b = c; c = a+b;
	}
	for(int i=1;i<=n;i++)
		printf("%c",(f[i])?'O':'o');
	return 0;
}