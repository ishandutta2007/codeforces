#include<bits/stdc++.h>
using namespace std;
const int N(333333);
struct Rec {
	long long t, w;
	bool operator < (const Rec & b) const {
		return t > b.t;
	}
} a[N];
int main() {
	int n;
   	long long myt, myw;
	cin >> n;
	cin >> myt >> myw;
	for(int i(1); i < n; i++) {
		cin >> a[i].t >> a[i].w;
	}
	sort(a + 1, a + n);
	int cur(1);
	int ans(n + 1);
	priority_queue<long long> pq;
	while(cur < n && a[cur].t > myt) {
		pq.push(a[cur].t - a[cur].w - 1);
		cur++;
	}
	ans = pq.size() + 1;
	//printf("%d\n", ans);
	for( ; myt > 0; ) {
		if(pq.empty()) {
			break;
		}
		long long delta(-pq.top());
		if(cur < n) {
			delta = min(delta, max(0ll, myt - a[cur].t + 1));
		}
		if(delta > myt) {
			break;
		}
		myt -= delta;
		while(cur < n && a[cur].t > myt) {
			pq.push(a[cur].t - a[cur].w - 1);
			cur++;
		}
		long long rmn(delta);
		//printf("%d %d\n", pq.size(), myt);
		while(!pq.empty() && rmn > 0) {
			long long v(pq.top());
			long long delta(min(-v, rmn));
			//cout << v << ' ' << delta << endl;
			v += delta;
			rmn -= delta;
			pq.pop();
			if(v < 0) {
				pq.push(v);
			}
		}
		//printf("%d %d\n", pq.size(), myt);
		ans = min(ans, (int)(pq.size() + 1));
	}
	cout << ans << endl;
}