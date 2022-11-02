#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <unordered_set>
using namespace std;


#define N 210000
unsigned int n, m;
vector <unsigned int> ve[N];
unsigned long long A, B, C;
set <unsigned long long> SS;
unordered_set <unsigned long long > Set[N];
unsigned long long ans;
bool in[N];

unsigned long long p(unsigned long long n) {
	if (n % 2 == 0)
		return (n / 2) * (n - 1);
	else
		return n * ((n - 1) / 2);
}

void get_triangle(unsigned int a, unsigned int b, unsigned int c) {
	if (a > b || a > c)
		return ;
	unsigned int x[3];
	x[0] = a, x[1] = b, x[2] = c;
	sort(x, x + 3);
	// long long BB = 1LL * x[0] * n * n + 1LL * x[1] * n + x[2];
	// if (SS.count(BB))
	// 	return ;
	// SS.insert(BB);
	ans -= x[0] * A + x[1] * B + x[2] * C;
}

int main() {
	scanf("%d%d", &n, &m);
	// scanf("%d%d%d", &A, &B, &C);
	cin >> A >> B >> C;
	for (unsigned int i = 1; i <= m; i++) {
		unsigned int x, y;
		scanf("%d%d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
		Set[x].insert(y);
		Set[y].insert(x);
		
	}
	ans = 0;
	for (unsigned int i = 0; i < n; i++) {
		ans += A * i * p(n - i - 1);
		ans += B * i * i * (n - i - 1);
		ans += C * i * p(i);
	}

	for (unsigned int i = 0; i < n; i++)
		for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++)
			if (ve[i][j] > i) {
				unsigned int k = ve[i][j];
				ans -= A * p(i);
				ans -= B * i * i;
				ans -= C * k * i;

				ans -= B * (p(k) - p(i + 1));
				ans -= A * i * (k - i - 1);
				ans -= C * k * (k - i - 1);

				ans -= C * (p(n) - p(k + 1));
				ans -= A * i * (n - k - 1);
				ans -= B * k * (n - k - 1);
			}

	for (unsigned int i = 0; i < n; i++) {
		unsigned long long l = 0, r = 0, L = 0, R = 0;
		for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++)
			if (ve[i][j] < i)
				l += 1, L += ve[i][j];
			else
				r += 1, R += ve[i][j];
		ans += B * i * l * r;
		ans += A * L * r;
		ans += C * R * l;


		ans += A * i * p(r);
		ans += C * i * p(l);
		// cout << "xx" << p(r) << endl;
		// cout << l << ' ' << r << endl;
		// cout << ans << endl;
		sort(ve[i].begin(), ve[i].end());
		for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++) {
			if (ve[i][j] < i) {
				unsigned int k = ve[i][j];
				ans += B * k * j;
				ans += A * k * (l - j - 1);
			}else {
				unsigned int k = ve[i][j];
				ans += B * k * (ve[i].size() - j - 1);
				// cout << ve[i].size() - j - 1 << endl;
				ans += C * k * (r - (ve[i].size() - j - 1) - 1);
				// cout << ans << ' ' << k << ' ' << (r - (ve[i].size() - j - 1) - 1) << endl;
				// cout << r - (ve[i].size() - j - 1) - 1 << endl;
			}
		}
		// cout << ans << endl;
	}

	// cout << ans << endl;
	// vector <unsigned int> V;
	for (unsigned int i = 0; i < n; i++)
		if (ve[i].size() <= 200) {
			for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++)
				for (unsigned int p = 0; p < j; p++)
					if (Set[ve[i][j]].count(ve[i][p]))
						get_triangle(i, ve[i][j], ve[i][p]);
		}else {
			for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++)
				in[ve[i][j]] = true;
			for (int a = 0; a < n; a++)
				if (in[a])
					for (int b = 0; b < (int) ve[a].size() && ve[a][b] < a; b++)
						if (in[ve[a][b]])
							get_triangle(i, a, ve[a][b]);
			for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++)
				in[ve[i][j]] = false;
		}

	// for (unsigned int i = 0; i < n; i++)
	// 	for (unsigned int j = 0; j < (unsigned int) ve[i].size(); j++) {
	// 		unsigned int k = ve[i][j];
	// 		for (unsigned int q = 0; q < (unsigned int) V.size(); q++) {
	// 			unsigned int k1 = V[q];
	// 			if (Set.count(1LL * i * n + k1) && Set.count(1LL * k * n + k1))
	// 				get_triangle(i, k, k1);
	// 		}
	// 	}
	cout << ans << endl;
}