#include <bits/stdc++.h>

int n, m;
int ans = 0;
int mark = false;

int main(){
	scanf("%d%d", &n, &m);
	int d1, h1, d2, h2;
	scanf("%d%d", &d1, &h1);
	ans = std::max(ans, d1 + h1 - 1);
	for(int i = 2; i <= m; ++ i){
		scanf("%d%d", &d2, &h2);
		int temp = d2 - d1 - 1 - abs(h1 - h2);
		//printf("tmp = %d\n", temp);
		if(temp > 0)
		    ans = std::max(ans, (temp + 1 >> 1) + std::max(h1, h2));
		else if(temp == 0 || temp == -1){
			ans = std::max(ans , std::max(h1, h2));
		}
		else{
			mark = true;
		}
		d1 = d2;
		h1 = h2;
	}
	ans = std::max(ans, n - d1 + h1);
	if(mark) return printf("IMPOSSIBLE\n"), 0;
	printf("%d\n", ans);
	return 0;
}