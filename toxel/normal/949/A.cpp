#include<bits/stdc++.h>

const int N = 200010;

std::vector <int> vec[N];
char s[N];
int cnt[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++ i){
		++ cnt[s[i] - '0'];
	}
	if (cnt[1] >= cnt[0]){
		printf("-1\n");
		return 0;
	}
	std::queue <int> q0, q1;
	for (int i = 0; i < cnt[0] - cnt[1]; ++ i){
		q0.push(i);
	}
	for (int i = 0; i < n; ++ i){
		if (s[i] == '0'){
			if (q0.empty()){
				puts("-1");
				return 0;
			}
			int x = q0.front();
			vec[x].push_back(i + 1);
			q0.pop();
			q1.push(x);
		}
		else{
			if (q1.empty()){
				puts("-1");
				return 0;
			}
			int x = q1.front();
			vec[x].push_back(i + 1);
			q1.pop();
			q0.push(x);
		}
	}
	if (!q0.empty()){
		puts("-1");
		return 0;
	}
	printf("%d\n", cnt[0] - cnt[1]);
	for (int i = 0; i < cnt[0] - cnt[1]; ++ i){
		printf("%d", (int) vec[i].size());
		for (auto u : vec[i]){
			printf(" %d", u);
		}
		putchar('\n');
	}
	return 0;
}