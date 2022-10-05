#include<bits/stdc++.h>

const int N = 1010;

char s[N];
int n, cnt[N];

int main(){
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; ++ i){
		if (!cnt[s[i]]){
			cnt[s[i]] = i;
		}
	}
	for (int i = 'a'; i < 'z'; ++ i){
		if (cnt[i + 1] && (!cnt[i] || cnt[i] > cnt[i + 1])){
			return printf("NO\n"), 0;
		}
	}
	return printf("YES\n"), 0;
}