#include<bits/stdc++.h>

const int N = 100010;

char s[N], str[3][N];
int len;

int solve(int type, int ret){
	int ans = 0;
	memcpy(str[type], s, sizeof(s));
	for (int i = len - 1; i >= 0; -- i){
		if ((str[type][i] - '0') % 3 == type){
			str[type][i] = '\0';
			++ ans;
			ret = (ret - type + 3) % 3;
			if (!ret){
				break;
			}
		}
	}
	for (int i = 0; i < len; ++ i){
		if (str[type][i] == 0){
			continue;
		}
		if (str[type][i] != '0' || len - ans == 1){
			break;
		}
		str[type][i] = '\0';
		++ ans;
	}
	return ret ? INT_MAX : ans;
}

int main(){
	scanf("%s", s);
	int sum = 0;
	len = strlen(s);
	for (int i = 0; i < len; ++ i){
		sum += s[i] - '0';
	}
	if (!(sum % 3)){
		return printf("%s", s), 0;
	}
	int ans1 = solve(1, sum % 3), ans2 = solve(2, sum % 3);
	int type = ans1 < ans2 ? 1 : 2;
	int cnt = 0;
	for (int i = 0; i < len; ++ i){
		if (str[type][i] != 0){
			++ cnt;
			putchar(str[type][i]);
		}
	}
	if (!cnt){
		return printf("-1\n"), 0;
	}
	return printf("\n"), 0;
}