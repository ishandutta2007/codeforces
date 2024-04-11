#include<bits/stdc++.h>

const int N = 100;

int n;
char s[N];

int main(){
	scanf("%d%s", &n, s);
	s[n ++] = '0';
	int ans = 0;
	for (int i = 0, now = 0; i < n; ++ i){
		if (s[i] == '0'){
			ans = ans * 10 + now;
			now = 0;
		}
		else{
			++ now;
		}
	}
	return printf("%d\n", ans), 0;
}