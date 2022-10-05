#include<bits/stdc++.h>

const int N = 1000;

char oper[N];
int ans[N];

int main(){
	int cntplus = 0, cntminus = 0, cnt = 0;
	while (~scanf("%s", oper + cnt)){
		if (!cnt){
			if (oper[cnt] == '?'){
				++ cntplus;
				oper[cnt] = '+';
			}
			else{
				++ cntminus;
				scanf("%s", oper + cnt + 1);
			}
			++ cnt;
		}
		scanf("%s", oper + cnt);
		++ cnt;
		if (oper[cnt - 1] == '+'){
			++ cntplus;
		}
		else if (oper[cnt - 1] == '-'){
			++ cntminus;
		}
		else{
			break;
		}
	}
	int n;
	scanf("%d", &n);
	int left = cntplus - n * cntminus;
	int right = cntplus * n - cntminus;
	if (left > n || right < n){
		return printf("Impossible\n"), 0;
	}
	printf("Possible\n");
	int _n = n;
	for (int i = 0; i < cnt - 1; ++ i){
		if (oper[i] == '+'){
			ans[i] = 1;
			-- _n;
		}
		else{
			ans[i] = -1;
			++ _n;
		}
	}
	for (int i = 0; i < cnt - 1 && _n; ++ i){
		if (_n < 0 && ans[i] < 0){
			int p = std::min(ans[i] + n, - _n);
			ans[i] -= p;
			_n += p;
		}
		else if (_n > 0 && ans[i] > 0){
			int p = std::min(n - ans[i], _n);
			ans[i] += p;
			_n -= p;
		}
	}
	if (oper[0] == '-'){
		putchar(oper[0]);
		putchar(' ');
	}
	for (int i = 0; i < cnt - 1; ++ i){
		printf("%d %c ", std::abs(ans[i]), oper[i + 1]);
	}
	return printf("%d\n", n), 0;
}