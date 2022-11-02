#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 112;
int a[N], b[N];

struct cmp {
	bool operator()(int i, int j) { return b[i] > b[j] || (b[i] == b[j] && i < j); }
};

struct op {
	int a, b, c;
};

void go(int l) {
	set<int, cmp> s;
	int i, j;
	vector<op> ops;
	for(i = 0; i < n; i++) {
		b[i] = a[i];
		if(b[i] > l) s.insert(i);
	}
	while(s.size() > 1 && b[*s.begin()] != b[*next(s.begin())]) {
		i = *s.begin();
		j = *s.rbegin();
		s.erase(i); s.erase(j);
		ops.pb({i, j, -1});
		if(--b[i] > l) s.insert(i);
		if(--b[j] > l) s.insert(j);
	}
	if(s.size() == 1) { return; }
	while(!s.empty()) {
		vector<int> mx; int val = b[*s.begin()];
		while(!s.empty() && b[*s.begin()] == val) {
			mx.pb(*s.begin()); s.erase(s.begin());
		}
		vector<int> bak = mx;
		int n = mx.size();
		assert(n > 1);
		if(n & 1) {
			ops.pb({mx[n-1], mx[n-2], mx[n-3]});
			mx.pop_back(); mx.pop_back(); mx.pop_back();
		}
		while(!mx.empty()) {
			assert(mx.size() >= 2);
			ops.pb({mx.back(), mx[mx.size() - 2], -1});
			mx.pop_back(); mx.pop_back();
		}
		for(int x : bak) b[x]--;
		if(val - 1 != l) for(int x : bak) s.insert(x);
	}
	printf("%d\n%d\n", l, (int) ops.size());
	for(op o : ops) {
		for(i = 0; i < n; i++)
			putchar('0' + (i == o.a || i == o.b || i == o.c));
		putchar('\n');
	}
	exit(0);
}

int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = *min_element(a, a + n); i > 0; i--)
		go(i);
	printf("0\n%d\n", (n - 1) * 100);
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < 100; j++) {
			for(k = 0; k < n; k++)
				putchar('0' + (k == i || k == i + 1));
			putchar('\n');
		}
}