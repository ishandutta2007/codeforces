#include<bits/stdc++.h>

const int N = 5010;

char s[N];
int cnt[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	int sum = 0;
	for (int i = 0; i < 26; ++ i){
		std::vector <int> sit;
		for (int j = 0; j < n; ++ j){
			if (s[j] == 'a' + i){
				sit.push_back(j);
			}
		}
		int max = 0;
		for (int j = 1; j < n; ++ j){
			for (auto u : sit){
				int ssit = u + j;
				ssit -= ssit >= n ? n : 0;
				++ cnt[s[ssit]];
			}
			int ccnt = 0;
			for (int k = 0; k < 26; ++ k){
				ccnt += cnt['a' + k] == 1;
				cnt['a' + k] = 0;
			}
			max = std::max(max, ccnt);
		}
		sum += max;
	}
	printf("%.10lf\n", 1.0 * sum / n);
	return 0;
}