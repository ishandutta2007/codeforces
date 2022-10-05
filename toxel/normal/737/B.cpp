#include<bits/stdc++.h>

const int N = 200010;

char s[N];

int main(){
	int n, a, b, k;
	scanf("%d%d%d%d%s", &n, &a, &b, &k, s + 1);
	s[0] = s[n + 1] = '1';
	std::vector <int> vec;
	for (int i = 0; i <= n + 1; ++ i){
		if (s[i] == '1'){
			vec.push_back(i);
		}
	}
	int sum = 0;
	for (int i = 0, sz = vec.size(); i < sz - 1; ++ i){
		sum += (vec[i + 1] - vec[i] - 1) / b;
	}
	printf("%d\n", sum - a + 1);
	int sit = vec[0], now = 0;
	while (sum > a - 1){
		if (vec[now + 1] - sit <= b){
			sit = vec[++ now];
		}
		else{
			printf("%d ", sit += b);
			-- sum;
		}
	}
	putchar('\n');
	return 0;
}