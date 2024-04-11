#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) { x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod) {
			if(y & 1)
			res = 1LL * res * x % mod;
		}
	}
}

int n, m, x, y, P2[N];

void pre(int n) {
	P2[0] = 1;
	for(int  i = 1 ; i <= n; ++ i) P2[i] = 1LL * P2[i - 1] * (mod + 1) / 2 % mod;
}

int ans[N], S[N], where[N];

vector <int> ad[N];

int main() {
	pre(N - 1);
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		int all = 1, dod = 0;
		for(int i = 1; i <= n; ++ i) ad[i].clear();
		for(int i = 1; i <= n; ++ i) {
			int now = (n - i + 2) / 2 - 1;
			// [i, i + now]
//			cerr << i <<' ' << now << endl;
			int beg = P2[now + (i != 1)];
			where[i] = i + now + 1;
			S[i] = beg;
			if(i != n)
			ad[i + now].push_back(i);
		}
//		cerr <<"HERE" << endl;
		
		for(int i = 1; i <= n; ++ i) {
			S[i] = 1LL * all * S[i] % mod;
			for(auto x : ad[i]) {
//				cerr << i <<' ' << x << endl;
				Sub(all, S[x]);
			}
//			printf("%d ", S[i]);
		}
		
		for(int i = n; i >= 1; -- i)
		printf("%d\n", S[i]);
		puts("");
	}
}