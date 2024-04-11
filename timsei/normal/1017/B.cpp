#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char A[N], B[N], C[N];
int n;
int tmp[2][2];

int main(void) {
	cin >> n;
	scanf("%s", A + 1);
	scanf("%s", B + 1);
	for(int i = 1; i <= n; ++ i) {
		A[i] -= '0';
		B[i] -= '0';
		++ tmp[A[i]][B[i]];
	}
	long long  ans = 0;
	for(int a = 0; a < 2; ++ a) {
		for(int b = 0;b < 2; ++ b) {
			for(int c = 0; c < 2; ++ c) {
				for(int d = 0; d < 2; ++ d) {
					if(make_pair(a, b) < make_pair(c, d)) {
						if(((a | b) != (c | b)) || (a | d) != (c | d)) {
							ans += 1LL * tmp[a][b] * tmp[c][d];
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}