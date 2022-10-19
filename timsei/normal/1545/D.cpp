#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int t, m, k, A[N][N];
long long sm1[N], sm2[N];

long long solve(int x) {
	// x - 1, x, x + 1
	return (sm2[x + 1] + sm2[x - 1] - 2 * sm2[x]);
}

int main() {
	
	cin >> m >> k;
	
	for(int i = 1; i <= k; ++ i) {
		for(int j = 1; j <= m; ++ j) scanf("%d", &A[i][j]), sm1[i] += A[i][j], sm2[i] += 1LL * A[i][j] * A[i][j];
	}
	
	map <int, int> Map;
	
	for(int i = 1; i < k; ++ i) {
		++ Map[sm1[i + 1] - sm1[i]];
	}
	
	int it = 0, who = 0;
	
	for(auto V : Map) if(V.second > 3) it = V.first;
	
	int cnt = 0;
	
	for(int i = 2; i <= k; ++ i) {
		if(sm1[1] + (i - 1) * it !=sm1[i]) ++ cnt, who = i;
	}
	
	if(cnt > 1) {
		who = 1;
	}
	
	cerr << sm1[1] + (who - 1) * it <<' ' << sm1[who] << endl;
	
	cerr << who << endl;
	
	long long C = solve((who <= 3) ? k - 1 : 2);
	long long ini = 0;
	if(who == 1) {
		ini = sm2[2] * 2 - sm2[3] + C;
	} else if(who == k) {
		ini = sm2[who - 1] * 2 - sm2[who - 2] + C;
	} else {
		ini = (sm2[who - 1] + sm2[who + 1] - C) / 2;
	}
	
	long long d1 = sm1[1] + (who - 1) * it - sm1[who], d2 = ini - sm2[who];
	for(int i = 1; i <= m; ++ i) {
		if(2 * d1 * A[who][i] + d1 * d1 == d2) {
			printf("%d %d\n", who - 1, A[who][i] + d1);
			return 0;
		}
	}
}