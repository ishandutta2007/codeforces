#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
const int N(55);
long long dp[N][N];
struct W {
	int a, b, c, d;
	W(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {
		
	}
	bool operator < (const W & x) const {
		return a * 125000 + b * 2500 + c * 50 + d < x.a * 125000 + x.b * 2500 + x.c * 50 + x.d;
	}
};
set<W> ans;
void insert(W a) {
	ans.insert(a);
	swap(a.a, a.b);
	swap(a.c, a.d);
	ans.insert(a);
}
int main() {
	long long t;
	scanf("%I64d", &t);
	for(int i(1); i <= 48; i++) {
		if(i >= 3 && (i - 3) % 2 == 0) {
			insert(W(i, i - 2, i + 1, i - 2));
			insert(W(i, i - 1, i + 1, i - 1));
			if(i != 47) {
				insert(W(i + 1, i - 1, i + 1, i));
				insert(W(i + 2, i - 1, i + 2, i));
			}

			if(i != 47) {
				insert(W(i + 1, i - 2, i + 2, i - 2));
				if(i != 45) {
					insert(W(i + 3, i - 1, i + 4, i - 1));
				}
			}
		}
	}
	ans.insert(W(47, 47, 47, 48));
	ans.insert(W(47, 47, 48, 47));
	for(int i(1); i <= 47; i++) {
		for(int j(1); j <= 47; j++) {
			if(i == 1 && j == 1) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = 0;
			if(i - 1 >= 1 && !ans.count(W(i - 1, j, i, j))) {
				dp[i][j] += dp[i - 1][j];
			}
			if(j - 1 >= 1 && !ans.count(W(i, j - 1, i, j))) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	for(int i(47); i >= 3; i -= 2) {
		if(i == 47 && t >= dp[i][i]) {
			ans.erase(W(i, i, i + 1, i));
			t -= dp[i][i];
		}
		if(i == 47 && t >= dp[i][i]) {
			ans.erase(W(i, i, i, i + 1));
			t -= dp[i][i];
		}
		if(t >= dp[i - 1][i]) {
			ans.erase(W(i - 1, i, i - 1, i + 1));
			t -= dp[i - 1][i];
		}
		if(t >= dp[i - 1][i]) {
			ans.erase(W(i, i - 1, i + 1, i - 1));
			t -= dp[i - 1][i];
		}
		if(t >= dp[i - 2][i]) {
			ans.erase(W(i - 2, i, i - 2, i + 1));
			t -= dp[i - 2][i];
		}
		if(t >= dp[i - 2][i]) {
			ans.erase(W(i, i - 2, i + 1, i - 2));
			t -= dp[i - 2][i];
		}
	}
	printf("48 48 %d\n", (int)ans.size());
	for(set<W>::iterator itr(ans.begin()); itr != ans.end(); itr++) {
		printf("%d %d %d %d\n", itr->a, itr->b, itr->c, itr->d);
	}
}