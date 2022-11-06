// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <bits/stdc++.h>
#define x first 
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;

template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) {if (x > y) x = y;} 
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) {if (x < y) x = y;} 

const string FILENAME = "input";
typedef pair<int, int> point;

const int MAXN = 2600 * 2;

point operator -(point a, point b) {
	return {a.x - b.x, a.y - b.y};
}

long long cross(point &a, point &b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}


long long cross1(point a, point b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int n;
point a[MAXN];
set<point> used;

long long A1, B1, C1, A2, B2, C2;

point v[MAXN];
vector<int> id;
vector<int> cool[MAXN];
vector<point> nv[MAXN];
long long t;

const point Z = {0, 0};

bool cmp(point a, point b) {
	return cross(a, b) < 0;
}

bool cmp2(int i, int j) {
	return cross(v[i], v[j]) < 0;
}


bool cmp1(int i, int j) {
	return cool[i].size() < cool[j].size();
}

int cnt = 1;
int usd[MAXN];

vector<int> num;

void check(int L, int Ln, int R, int Rn) {
	//cout << L + 1 << ' ' << Ln + 1 << ' ' << R + 1 << ' ' << Rn + 1 << endl;
	point v1 = a[Ln] - a[L];
	A1 = v1.y;
	B1 = -v1.x;
	C1 = -(A1 * a[L].x + B1 * a[L].y);
	point v2 = a[Rn] - a[R];
	if (cross(v1, v2) == 0) return;
	A2 = v2.y;
	B2 = -v2.x;
	C2 = -(A2 * a[R].x + B2 * a[R].y);
	point moon;
	long long w1 = C2 * A1 - C1 * A2, k = B1 * A2 - B2 * A1;
	if (w1 % k != 0) return;
	moon.y = w1 / k;
	long long w2 = C2 * B1 - C1 * B2;
	if (w2 % k != 0) return;
	moon.x = w2 / (-k);
	if (max(abs(moon.y), abs(moon.x)) > 1e6) return;
	if (used.count(moon)) return;
	// if ((clock() - t) > CLOCKS_PER_SEC * 4.8) {
	// 	printf("No");
	// 	exit(0);
	// }
	//cout << moon.x << ' ' << moon.y << endl;
	++cnt;
	for (int i : num) {
		if (usd[i] == cnt) continue;
		point v = moon - a[i];
		if (v.x < 0 || (v.x == 0 && v.y < 0)) {
			v.x *= -1;
			v.y *= -1;
		}
		auto it = lower_bound(nv[i].begin(), nv[i].end(), v, cmp);
		if (it == nv[i].end()) return;
		int j = cool[i][int(it - nv[i].begin())];
		if (cross1(a[i] - moon, a[j] - moon) != 0) return;
		usd[j] = cnt;
	}
	printf("Yes\n%d %d", moon.x, moon.y);
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	srand(time(0));
	t = clock();
	//read(FILENAME);
//	freopen("input.txt", "r", stdin);
	
	scanf("%d", &n);
	n *= 2;

	//n = 5200;
	int L, R, M;
	// for (int i = 0; i < n; i += 2) {
	// 	a[i].x = i;
	// 	a[i].y = rand() % 1000000 + 1;
	// 	a[i + 1] = Z - a[i];

	// }
	// a[n - 2].y--;
	// a[n - 1].y++;
	for (int i = 0; i < n; ++i) {
		//cout << a[i].x << ' ' << a[i].y << endl;
		scanf("%d%d", &a[i].x, &a[i].y);
		used.insert(a[i]);
		id.pb(i);
		num.pb(i);
	}
	//random_shuffle(num.begin(), num.end());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			v[j] = a[j] - a[i];
			if (v[j].x < 0 || (v[j].x == 0 && v[j].y < 0)) {
				v[j].x *= -1;
				v[j].y *= -1;
			}
		}
		id.erase(find(id.begin(), id.end(), i));
		sort(id.begin(), id.end(), cmp2);
		for (int j = 0; j < n - 1; ++j) {
			if (j != 0 && cross(v[id[j - 1]], v[id[j]]) == 0) continue;
			if (j != (n - 2) && cross(v[id[j + 1]], v[id[j]]) == 0) continue;
			cool[i].pb(id[j]);
			nv[i].pb(v[id[j]]);
		}
		id.pb(i);
		if (cool[i].size() == 0) {
			printf("No");
			return 0;
		}
	}
	sort(id.begin(), id.end(), cmp1);
	L = id[0];
	R = id[1];
	M = id[2];
	for (int i : cool[L]) {
		if (i == R) {
			for (int Mn : cool[M]) {
				if (Mn == L || Mn == R) continue;
				check(L, R, M, Mn);
			}
		}
	}
	for (int Ln : cool[L]) {
		if (Ln == R) continue;
		for (int Rn : cool[R]) {
			if (Rn == L || Rn == Ln) continue;
			check(L, Ln, R, Rn);
		} 
	}
	printf("No");
}