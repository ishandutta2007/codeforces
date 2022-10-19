#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

struct Seg {
	int l, r;
};

int A[N], B[N], n, m, x, y, l, l1, r1, l2, r2, a, b, l3, r3;
char s[N];

bool ok1(int x, int l, int r, int l1, int r1) {

	if(r1 + x >= l && r1 + x <= r)  {
		a = x, b = r1 + x;
		return 1;
	}
	
	if(l1 + x >= l && l1 + x <= r) {
		a = x, b = l1 + x;
		return 1;
	}
	return 0;
}

bool ok2(int x, int l, int r, int l1, int r1) {	
	if(x - l1 >= l && x - l1 <= r) {
		a = x - l1, b = x;
		return 1;
	}
	
	if(x - r1 >= l && x - r1 <= r)  {
		a = x - r1, b = x;
		return 1;
	}
	return 0;
}

bool pd(int x) {
	l1 = 0, r1 = 1e9, l2 = 0, r2 = 1e9, l3 = -1e9, r3 = 1e9;
	for(int i = 1; i <= n; ++ i) {
		l1 = max(l1, A[i] - x);
		r1 = min(r1, A[i] + x);
		l2 = max(l2, B[i] - x);
		r2 = min(r2, B[i] + x);
	}
	for(int i = 1; i <= n; ++ i) {
		int L = (B[i] - A[i] - x), R = B[i] - A[i] + x;
		l3 = max(l3, L);
		r3 = min(r3, R);
	}
	
	if(l1 > r1 || l2 > r2 || l3 > r3) return 0;
	//[l3, r3]
	if(ok1(r1, l2, r2, l3, r3)) {
		return 1;
	}
	if(ok1(l1, l2, r2, l3, r3)) {
		return 1;
	}
	if(ok2(r2, l1, r1, l3, r3)) {
		return 1;
	}
	if(ok2(l2, l1, r1, l3, r3)) 
	return 1;
	return 0;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s + 1);
		l = strlen(s + 1);
		for(int j = 1; j <= l; ++ j)
		A[i] += (s[j] == 'B'),
		B[i] += (s[j] == 'N');
	}
	int l = 0, r = 1e6, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res << endl;
	pd(res);
	for(int i = 1; i <= a; ++ i) putchar('B');
	for(int i = 1; i <= b; ++ i) putchar('N');
}