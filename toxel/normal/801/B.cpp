#include<bits/stdc++.h>

const int N = 110;

char a[N], b[N];

int main(){
	scanf("%s%s", a, b);
	int len = strlen(a);
	for (int i = 0; i < len; ++ i){
		if (a[i] < b[i]){
			return printf("-1\n"), 0;
		}
	}
	return printf("%s\n", b), 0;
}