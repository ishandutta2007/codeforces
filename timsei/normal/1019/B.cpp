#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int n, A[N];

int query(int x) {
	cout << "?" << " " << x << endl;
	fflush(stdout);
	cin >> x;
	return x;
}

int out(int x) {
	cout << "! " << x << endl;
	fflush(stdout);
	exit(0);
}

int f(int x) {
	return A[(n / 2 + x - 1) % n + 1] - A[x];
}

main(void) {
	scanf("%lld", &n);
	if(n % 4 != 0) {
		out(-1);
		return 0;
	}
	A[1] = query(1);
	A[n / 2 + 1] = query(n / 2 + 1);
	if(A[1] == A[n / 2 + 1]) {
		out(1);
		return 0;
	}
	int l = 1, r = n / 2 + 1, res = -1;
	while(l + 1 <= r - 1) {
		int mid = (l + 1 + r - 1) >> 1;
		A[mid] = query(mid);
		A[mid + (n / 2)]= query(mid + n / 2);
		if(f(mid) == 0) {
			out(mid);
			return 0;
		}
		else {
			if((f(l) > 0 && f(mid) > 0) || (f(l) < 0 && f(mid) < 0)) l = mid;
			else r = mid;
		}
	}
	out(-1);
}