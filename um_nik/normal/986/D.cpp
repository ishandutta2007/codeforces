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

typedef complex<double> cd;

const double PI = 4 * atan(1);

const ll B = (ll)1000;
const int LOG = 19;
const int N = (1 << LOG);
const int NN = N + 5;
cd w[NN];
int rev[NN];

void printVec(vector<ll> a) {
	for (ll x : a)
		eprintf("%lld ", x);
	eprintf("\n");
}

void initFFT() {
	for (int i = 0; i < N; i++)
		w[i] = cd(cos(2 * PI * i / N), sin(2 * PI * i / N));
	rev[0] = 0;
	for (int mask = 1; mask < N; mask++) {
		int k = 0;
		while(((mask >> k) & 1) == 0) k++;
		rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (LOG - 1 - k));
	}
}

cd F[2][NN];
void FFT(cd* A, int k) {
	int L = 1 << k;
	for (int i = 0; i < L; i++)
		F[0][rev[i] >> (LOG - k)] = A[i];
	int t = 0, nt = 1;
	for (int lvl = 0; lvl < k; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < L; st += (len << 1))
			for (int i = 0; i < len; i++) {
				cd ad = F[t][st + len + i] * w[i << (LOG - 1 - lvl)];
				F[nt][st + i] = F[t][st + i] + ad;
				F[nt][st + len + i] = F[t][st + i] - ad;
			}
		swap(t, nt);
	}
	for (int i = 0; i < L; i++)
		A[i] = F[t][i];
}

cd A[NN];

bool ls(vector<ll> a, vector<ll> b) {
	if ((int)a.size() != (int)b.size()) return (int)a.size() < (int)b.size();
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return false;
}

vector<ll> sqr(vector<ll> a) {
	int L = (int)a.size();
	int k = 0;
	while(L > (1 << k)) k++;
	k++;
	L = 1 << k;
	for (int i = 0; i < L; i++)
		A[i] = 0;
	for (int i = 0; i < (int)a.size(); i++)
		A[i] = a[i];
	FFT(A, k);
	for (int i = 0; i < L; i++)
		A[i] *= A[i];
	FFT(A, k);
	vector<ll> res;
	res.resize(L);
	for (int i = 0; i < L; i++)
		res[i] = (ll)(A[i].real() / L + 0.5);
	reverse(res.begin() + 1, res.end());
	ll d = 0;
	for (int i = 0; i < L; i++) {
		d += res[i];
		res[i] = d % B;
		d /= B;
	}
	while((int)res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

vector<ll> multBy(vector<ll> a, ll x) {
	ll d = 0;
	for (int i = 0; i < (int)a.size() || d; i++) {
		if (i >= (int)a.size()) a.push_back(0LL);
		d += a[i] * x;
		a[i] = d % B;
		d /= B;
	}
	return a;
}

vector<ll> pow3(int pw) {
	vector<ll> res;
	res.push_back(1LL);
	int k = 0;
	while(pw >= (1 << k)) k++;
	for (int i = k - 1; i >= 0; i--) {
		res = sqr(res);
		if ((pw >> i) & 1)
			res = multBy(res, 3);
	}
	return res;
}

char s[3 * NN];
vector<ll> c;
int ANS = (int)1e9;

int read() {
	scanf("%s", s);
	int L = strlen(s);
	for (int pos = L; pos > 0; pos -= 3) {
		ll x = 0;
		for (int i = pos - 3; i < pos; i++) {
			if (i < 0) continue;
			x = x * 10 + (ll)(s[i] - '0');
		}
		c.push_back(x);
	}
	return L;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	initFFT();
/*
	vector<ll> a = pow3(59);
	printVec(a);
	return 0;
*/

	int pw = (int)(read() * log(10) / log(3)) - 6;
	pw = max(pw, 0);
	vector<ll> st = pow3(pw);

//	printVec(st);

	for (int k = 0; k < 3; k++) {
		int curAns = pw * 3 + k * 2;
		vector<ll> cur = multBy(st, 1LL << k);
		while(ls(cur, c)) {
			curAns += 3;
			cur = multBy(cur, 3LL);
		}
		ANS = min(ANS, curAns);
	}
	ANS = max(ANS, 1);
	printf("%d\n", ANS);

	return 0;
}