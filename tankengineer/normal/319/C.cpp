#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100005;
const long long MOD = 1000000000000000ll;

int n, q[N], h[N], qhead, qtail;
long long a[N], b[N];

struct gjd {
	long long l1, l2;
	gjd(long long a = 0) {
    l1 = a / MOD; l2 = a % MOD;
	}
}f[N], INF;

void print(gjd a) {
	if (a.l1 == 0) {
		cout << a.l2 << endl;
	} else {
	  cout << a.l1;
	  long long mul = 10;
	  while (a.l2 * mul < MOD && mul < MOD) {
	    cout << 0;
	    mul *= 10;
		}
		cout << a.l2 << endl;
	}
}

bool operator < (gjd a, gjd b) {
  return a.l1 < b.l1 || a.l1 == b.l1 && a.l2 < b.l2;
}

void pluss(gjd &a, gjd b) {
	a.l2 = a.l2 + b.l2;
	a.l1 = a.l1 + b.l1 + a.l2 / MOD;
	a.l2 %= MOD;
}

gjd cal(const int i, const int j) {
  gjd ret = f[j];
  pluss(ret, gjd(b[i] * a[j]));
  return ret;
}

int cal2(const int i, const int j) {
	if (j == 0) return n;
  //bisearch for k where b[k] * a[i] + f[i] <= b[k] * a[j] + f[j]
  int l = 0, r = n, m;
  while (r - l > 1) {
    m = (r + l) / 2;
    if (!(cal(m, j) < cal(m, i))) l = m; else r = m;
	}
  return l;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	qhead = qtail = 0;
	for (int i = n - 1; i > 0; --i) {
		while (qtail > qhead && (cal2(i + 1, q[qtail]) >= h[qtail])) --qtail;
		h[qtail + 1] = cal2(i + 1, q[qtail]);
		q[++qtail] = i + 1;
		while (qtail > qhead + 1 && !(cal(i, q[qhead + 1]) < cal(i, q[qhead + 2]))) ++qhead; 
		int tmp = q[qhead + 1];
		f[i] = cal(i, tmp);
		///printf("%d %d %d\n", q[qtail], q[qtail - 1], h[qtail]);
		///print(f[i]);
	}
	print(f[1]);
	return 0;
}