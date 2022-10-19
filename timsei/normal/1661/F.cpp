#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 5;

int n, t, k;
long long A[N], S2[N], S[N], ans, m;

int sqr(int x) {
	return x * x;
}

struct Node {
	int Len, num, More;
	friend bool operator < (Node a, Node b) {
		return a.More < b.More;
	}
};

priority_queue < Node > q;

int calc(int Len, int num) {
	if(num >= Len) return 1e18;
	else {
		long long now = Len / (num + 1);
		long long a = Len % (num + 1), b = num + 1 - a;
		return sqr(now + 1) * a + sqr(now) * b;
	}
}

int calc2(Node a, int b) {
	int l = 1, r = a.Len - 1 - a.num, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(calc(a.Len, a.num + mid - 1) - calc(a.Len, a.num + mid) >= b) {
			res = mid; l = mid + 1;
		} else r = mid - 1;
	}
	return res;
}

void rmain() {
	scanf("%lld", &n);
	long long ans = 0;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), ans += sqr(A[i] - A[i - 1]);
	q.push((Node){1, 1, 0});
	scanf("%lld", &m);
	if(ans <= m)  {
		puts("0");
		return;
	} else {
		ans -= m;
		int tot2 = 0;
//		cerr << q.size() <<  endl;
		int l = 1, r = 1e18, res = -1, it2 = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			int tot = 0, it = ans;
			for(int i = 1; i <= n; ++ i) {
				int mx = 0;
				if(calc(A[i] - A[i - 1], 0) - calc(A[i] - A[i - 1], 1) < mid) {
					mx = 0;
				} else 
				mx = calc2((Node){A[i] - A[i - 1], 0, calc(A[i] - A[i - 1], 0) - calc(A[i] - A[i - 1], 1)}, mid);
				tot += mx;
				it -= calc(A[i] - A[i - 1], 0) - calc(A[i] - A[i - 1], mx);
			}
			if(it > 0) {
				r = mid - 1; tot2 = tot; res = mid; it2 = it;
			} else l = mid + 1;
		}
		
		int mid = res; ans = it2;
		for(int i = 1; i <= n; ++ i) {
			int mx = 0;
			if(calc(A[i] - A[i - 1], 0) - calc(A[i] - A[i - 1], 1) < mid) {
				mx = 0;
			} else 
			mx = calc2((Node){A[i] - A[i - 1], 0, calc(A[i] - A[i - 1], 0) - calc(A[i] - A[i - 1], 1)}, mid);
			q.push((Node){A[i] - A[i - 1], mx,  calc(A[i] - A[i - 1], mx) - calc(A[i] - A[i - 1], mx + 1)});
		}		
		
		int tot = tot2;
		while(!q.empty()) {
			Node a = q.top();
			q.pop();
			Node b = q.top();
			q.pop();
			q.push(b);
			int mx = calc2(a, b.More);
			//cerr << a.Len <<' ' << a.num <<' ' << mx <<' ' << b.Len <<' ' << b.num << endl;
			if(ans <= calc(a.Len, a.num) - calc(a.Len, a.num + mx)) {
				int l = 1, r = mx, res = -1;
				while(l <= r) {
					int mid = (l + r) >> 1;
					if(calc(a.Len, a.num) - calc(a.Len, a.num + mid) >= ans) {
						res = mid; r = mid - 1;
					} else l = mid + 1;
				}
				//assert(res != -1);
				tot += res;
				break;
			} else {
				tot += mx;
				ans -= calc(a.Len, a.num) - calc(a.Len, a.num + mx);
				q.push((Node){a.Len, a.num + mx, calc(a.Len, a.num + mx) - calc(a.Len, a.num + mx + 1)});
			}
			if(ans <= 0) break;
		}
		cout << tot << endl;
	}
}

main() {
	for(t = 1; t --;) {
		rmain();
	}
}