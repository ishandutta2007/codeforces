#include<bits/stdc++.h>

const int N = 1010;

char s1[N], s2[N], status[N];
int vis[N];

int main(){
	scanf("%s%s", s1, s2);
	int len = strlen(s1);
	bool flag  = true;
	for (int i = 0; i < len; ++ i){
		if (s1[i] == s2[i]){
			if(status[s1[i]] && status[s1[i]] != '='){
				flag = false;
				break;
			}
			status[s1[i]] = '=';
		}
		else{
			if (status[s1[i]] && status[s1[i]] != s2[i]){
				flag = false;
				break;
			}
			status[s1[i]] = s2[i];
			if (status[s2[i]] && status[s2[i]] != s1[i]){
				flag = false;
				break;
			}
			status[s2[i]] = s1[i];
		}
	}
	if (!flag){
		return printf("-1\n"), 0;
	}
	int cnt = 0;
	std::vector <std::pair <char, char>> vec;
	for (int i = 0; i < N; ++ i){
		if (vis[i]){
			continue;
		}
		if (status[i] && status[i] != '='){
			++ cnt;
			vec.push_back({i, status[i]});
			vis[i] = true;
			vis[status[i]] = true;
		}
	}
	printf("%d\n", cnt);
	for (auto u : vec){
		printf("%c %c\n", u.first, u.second);
	}
	return 0;
}