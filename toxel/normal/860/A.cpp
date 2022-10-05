#include<bits/stdc++.h>

const int N = 3010;

char s[N];

int main(){
	scanf("%s", s);
	int len = strlen(s), pre = -1;
	bool flag = false;
	for (int i = 0; i < len; ++ i){
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			pre = i;
			putchar(s[i]);
			flag = false;
			continue;
		}
		if (s[i] != s[pre + 1]){
			flag = true;
		}
		if (flag && i - pre >= 3){
			putchar(' ');
			flag = false;
			pre = i - 1;
		}
		putchar(s[i]);
	}
	putchar('\n');
	return 0;
}