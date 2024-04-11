#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 400400;
bool REV = false;
vector<pii> a, b;
vector<pii> ans;
char s[N];

vector<pii> read() {
	scanf("%s", s);
	int L = strlen(s);
	char cur = 'c';
	int len = 0;
	vector<pii> res;
	for (int i = 0; i < L; i++) {
		if (cur == s[i]) {
			len++;
			continue;
		}
		if (len != 0) {
			res.push_back(mp((int)(cur - 'a'), len));
		}
		cur = s[i];
		len = 1;
	}
	if (len != 0)
		res.push_back(mp((int)(cur - 'a'), len));
	reverse(res.begin(), res.end());
	return res;
}

void makeMove(int X, int Y) {
	vector<pii> c, d;
	int sumX = 0, sumY = 0;
	while(X--) {
		sumX += a.back().second;
		c.push_back(a.back());
		a.pop_back();
	}
	while(Y--) {
		sumY += b.back().second;
		d.push_back(b.back());
		b.pop_back();
	}
	if (REV) swap(sumX, sumY);
	ans.push_back(mp(sumX, sumY));
	while(!c.empty()) {
		pii t = c.back();
		c.pop_back();
		if (b.empty() || b.back().first != t.first)
			b.push_back(t);
		else
			b.back().second += t.second;
	}
	while(!d.empty()) {
		pii t = d.back();
		d.pop_back();
		if (a.empty() || a.back().first != t.first)
			a.push_back(t);
		else
			a.back().second += t.second;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	a = read();
	b = read();

	if ((int)a.size() > (int)b.size()) {
		REV = true;
		swap(a, b);
	}

	int X = a.back().first;
	for (int i = 0; i < (int)a.size(); i++)
		a[i].first ^= X;
	for (int i = 0; i < (int)b.size(); i++)
		b[i].first ^= X;

	if ((int)a.size() == 1) {
		if (b.back().first == 0) {
			makeMove(0, ((int)b.size() / 4) * 2 + 1);
		} else {
			if ((int)b.size() > 1)
				makeMove(1, ((int)b.size() / 4) * 2 + 1);
		}
	} else {
		if (b.back().first == 0) {
			if (((int)b.size() - (int)a.size()) % 4 == 3) {
				makeMove(1, 2);
			}
			makeMove(0, (((int)b.size() - (int)a.size()) / 4) * 2 + 1);
		} else {
			if (((int)b.size() - (int)a.size()) % 4 == 3) {
				makeMove(1, (((int)b.size() - (int)a.size()) / 4) * 2 + 3);
			} else {
				makeMove(1, (((int)b.size() - (int)a.size()) / 4) * 2 + 1);
			}
		}
	}

	while((int)a.size() > 1 || (int)b.size() > 1)
		makeMove(1, 1);

	printf("%d\n", (int)ans.size());
	for (pii t : ans)
		printf("%d %d\n", t.first, t.second);

	return 0;
}