#include<bits/stdc++.h>

int main(){
	int n;
	scanf("%d", &n);
	putchar('a');
	for (int i = 1; i < n; ++ i){
		putchar(i + 1 >> 1 & 1 ? 'b' : 'a');
	}
	return 0;
}