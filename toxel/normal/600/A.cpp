#include<bits/stdc++.h>

const int N = 100010;

char s[N], ans1[N], ans2[N];

void print(char *ans, int begin, int end, int &len){
	for (int i = begin; i < end; ++ i){
		ans[len ++] = s[i];
	}
	ans[len ++] = ',';
}

int main(){
	scanf("%s", s);
	int len = strlen(s), pre = -1, len1 = 0, len2 = 0;
	s[len ++] = ',';
	for (int i = 0; i < len; ++ i){
		if (s[i] == ',' || s[i] == ';'){
			bool flag = true;
			for (int j = pre + 1; j < i; ++ j){
				if (s[j] < '0' || s[j] > '9'){
					flag = false;
					break;
				}
			}
			flag = flag && i - pre >= 2 && (i - pre == 2 || s[pre + 1] != '0');
			print(flag ? ans1 : ans2, pre + 1, i, flag ? len1 : len2);
			pre = i;
		}
	}
	ans1[-- len1] = '\0';
	ans2[-- len2] = '\0';
	if (len1 >= 0){
		printf("\"%s\"\n", ans1);
	}
	else{
		printf("-\n");
	}
	if (len2 >= 0){
		printf("\"%s\"\n", ans2);
	}
	else{
		printf("-\n");
	}
}