#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

#define int long long

long long n, m, x, y, A[N];

long long S[N], Min[N], D[N];

vector < long long> ans;

multiset < long long > L, R;

#define lowbit(x) (x & (-x))

struct BIT {
	long long S[N];
	void add(int x, int v) {
		++ x;
		for(int i = x; i < N; i += lowbit(i))
		S[i] += v;
	}
	long long Sum(int x) {
		++ x;
		long long res = 0;
		for(int i = x; i; i -= lowbit(i))
		res += S[i];
		return res;
	}
	void init() {
		memset(S, 0, sizeof(S));
	}
	
	long long Q(int l, int r) {
		if(l > r) return 0;
		return Sum(r) - Sum(l - 1);
	}
}B1, B2;

int ok[N];

main() {
	cin >> n;
	B1.init(); B2.init();
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	sort(A + 1, A + n + 1);
	reverse(A + 1, A + n + 1);
	for(int i = 1; i <= n; ++ i) {
		S[i] = S[i - 1] + A[i];
		D[i] = S[i];
	}
	//for(int i = 1; i <= n; ++ i) cerr << A[i] <<" "; cerr << endl;
	int it = n + 1;
	for(int i = n; i >= 1; -- i) {
		S[i] -= 1LL * i * (i - 1);
		S[i] -= B1.Q(1, i) + (1LL * B2.Q(i + 1, n) * i);
		B1.add(A[i], A[i]);
		B2.add(A[i], 1);
		L.insert(S[i]);
		if(S[i] > i) {
			it = i;
		}
		//cerr << i <<' ' << S[i] << endl;
	}
	B1.init(); B2.init();
	bool rdied = 0;
	for(int i = n + 1; i >= 1; -- i) {
		long long l = 0, r = n;
		if(i != 1) {
			l = max(l, (*L.rbegin()) + 0LL);
			r = min(r, (long long)A[i - 1]);
		}
		if(i <= n) {
			r = min(r, (*R.begin()) + 0LL);
			l = max(l, A[i] + 0LL);
		}
		long long me = D[i - 1] - 1LL * i * (i - 1) - B1.Q(1, i) - 1LL * B2.Q(i + 1, n) * i;
		r = min(r, -me);
		//cerr << l <<" " << r <<" " << it <<" " << me <<": " << i <<" " << A[i - 1] <<" " << A[i] <<  endl;
		if(!rdied && i <= it) {
			if(l <= r) ++ ok[l], -- ok[r + 1];
		}
		if(i != 1) {
			L.erase(L.find(S[i - 1]));
			S[i - 1] = D[i - 1] - 1LL * i * (i - 1) - B1.Q(1, i) - 1LL * B2.Q(i + 1, n) * i;
			if(S[i - 1] > 0) break;
			R.insert(-S[i - 1]);
			B1.add(A[i - 1], A[i - 1]);
			B2.add(A[i - 1], 1);
		}
	}
	vector <int > All; All.clear();
	int Sum = 0;
	for(int i = 1; i <= n; ++ i) Sum = (Sum + A[i]) % 2;
	for(int i = 1; i <= n; ++ i) if((ok[i] += ok[i - 1]) && ((Sum & 1) == (i & 1))) All.push_back(i);
	if((Sum & 1) == 0 && ok[0]) All.push_back(0);
	sort(All.begin(), All.end());
	if(!All.size()) {
		puts("-1");
	}
	else {
		for(int i = 0; i < (int) All.size(); ++ i) printf("%d ", All[i]);
	}
}