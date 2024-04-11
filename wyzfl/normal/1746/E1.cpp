#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

int n;

string query(vector<int> vec) {
	printf("? ");
	printf("%d ", (int)vec.size());
	for (auto i: vec) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	string ans;
	cin >> ans;
	return ans;
}

vector<int> operator+(vector<int> a, vector<int> b) {
	for (auto i: b) a.push_back(i);
	return a;
}

void solve(vector<int> vec) {
	if (vec.size() == 2) {
		printf("! %d\n", vec[0]);
		string ans;
		cin >> ans;
		if (ans == ":)") exit(0);
		printf("! %d\n", vec[1]);
		exit(0);
	}
	int len = (int)vec.size() / 3;
	vector<int> nvec[3];
	for (int i = 0; i < len; i++) nvec[0].push_back(vec[i]);
	for (int i = len; i < len * 2; i++) nvec[1].push_back(vec[i]);
	for (int i = len * 2; i < (int)vec.size(); i++) nvec[2].push_back(vec[i]);
	string tmp = query(nvec[0]);
	if (tmp == "NO") {
		tmp = query(nvec[0]);
		if (tmp == "NO") {
			solve(nvec[1] + nvec[2]);
			return;
		}
	}
	tmp = query(nvec[1]);
	if (tmp == "YES")
		solve(nvec[0] + nvec[1]);
	else
		solve(nvec[0] + nvec[2]);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	if (n == 1) {
		printf("! 1\n");
		return 0;
	}
	vector<int> vec(n);
	for (int i = 0; i < n; i++) vec[i] = i + 1;
	solve(vec);
}