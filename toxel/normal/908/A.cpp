#include<bits/stdc++.h>

const int N = 100010;

char s[N];

int main(){
	scanf("%s", s);
	int n = strlen(s), cnt = 0;
	for (int i = 0; i < n; ++ i){
		cnt += s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || (s[i] >= '0' && s[i] <= '9' && s[i] - '0' & 1);
	}
	printf("%d\n", cnt);
	return 0;
}