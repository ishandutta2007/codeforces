#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 45;

char s[N];
int len, a, b;
bool was[N][N][N];
bool dp[N][N][N][N];
tuple<int, int, int, int> from[N][N][N][N];
int save[N][N][N];

void Clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					dp[i][j][x][y] = false;
					was[i][j][x] = false;
				}
			}
		}
	}
}

int myPow(int x, int y, int md) {
	if (was[x][y][md]) {
		return save[x][y][md];
	}
	was[x][y][md] = true;
	int Sx = x, Sy = y;
	while (y--) {
		x = (x * 10) % md;
	}
	save[Sx][Sy][md] = x % md;
	return save[Sx][Sy][md];
}

void Rec(int pos, int ta, int cA, int cB) {
	//printf("at:  %d %d %d %d\n", pos, ta, cA, cB);
	if (pos >= len) return;
	int Pos = get<0>(from[pos][ta][cA][cB]);
	int Ta = get<1>(from[pos][ta][cA][cB]);
	int CA = get<2>(from[pos][ta][cA][cB]);
	int CB = get<3>(from[pos][ta][cA][cB]);
	if (Ta != ta) printf("R");
	else printf("B");
	Rec(Pos, Ta, CA, CB);
}

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %d %d", &len, &a, &b);
		scanf("%s", s);
		Clear();
		dp[len][0][0][0] = true;
		from[len][0][0][0] = {len, 0, 0, 0};
		for (int i = len - 1; i >= 0; i--) {
			int dig = s[i] - '0';
			for (int j = 0; j < len - i; j++) {
				for (int cA = 0; cA < a; cA++) {
					for (int cB = 0; cB < b; cB++) {
						if (dp[i + 1][j][cA][cB]) {
							{
								int ncA = (cA + myPow(dig, j, a)) % a;
								dp[i][j + 1][ncA][cB] = true;
								from[i][j + 1][ncA][cB] = {i + 1, j, cA, cB};
							}
							{
								int ncB = (cB + myPow(dig, len - i - j - 1, b)) % b;
								dp[i][j][cA][ncB] = true;
								from[i][j][cA][ncB] = {i + 1, j, cA, cB};
							}
						}
					}
				}
			}
		}
		bool found = false;
		int best = 0;
		for (int take = 1; take < len; take++) {
			if (dp[0][take][0][0]) {
				if (abs(best - (len - best)) > abs(take - (len - take))) {
					best = take;
				}
				found = true;
			}
		}
		if (!found) {
			printf("-1\n");
		} else {
			Rec(0, best, 0, 0);
			printf("\n");
		}
	}
	return 0;
}