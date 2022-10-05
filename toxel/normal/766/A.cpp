#include<bits/stdc++.h>

const int N = 100010;

char a[N], b[N];

int main(){
	scanf("%s%s", a, b);
	int lena = strlen(a), lenb = strlen(b);
	if (!strcmp(a, b)){
		return printf("-1\n"), 0;
	}
	return printf("%d\n", std::max(lena, lenb)), 0;
}