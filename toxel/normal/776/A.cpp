#include<bits/stdc++.h>

const int N = 20;

char a[N], b[N], c[N], d[N];
int n;

int main(){
	scanf("%s%s%d", a, b, &n);
	printf("%s %s\n", a, b);
	for (int i = 0; i < n; ++ i){
		scanf("%s%s", c, d);
		if (!strcmp(a, c)){
			memcpy(a, d, sizeof(d));
		}
		else{
			memcpy(b, d, sizeof(d));
		}
		printf("%s %s\n", a, b);
	}
	return 0;
}