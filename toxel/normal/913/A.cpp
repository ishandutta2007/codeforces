#include<bits/stdc++.h>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if (n >= 30){
		return printf("%d\n", m), 0;
	}
	return printf("%d\n", m % (1 << n)), 0;
}