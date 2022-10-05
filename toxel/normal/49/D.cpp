#include<bits/stdc++.h>

const int N = 1010;

char s[N];

int main(){
	int len;
	scanf("%d%s", &len, s);
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < len; ++ i){
		ans1 += s[i] - '0' + i & 1;
		ans2 += s[i] - '0' + i + 1 & 1;
	}
	return printf("%d\n", std::min(ans1, ans2)), 0;
}