#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>

typedef long long ll;

const int ms = 100100;
const int bs = 330;

ll sum[ms];
ll a[ms], b[ms];
int freq[ms];
int to[ms], to2[ms], from[ms];
std::map<ll, int> hmm;
ll ans[ms];

int n;
ll k;

struct qry{
	int l, r, idx;
	void read(int id) {
		idx = id;
		//std::cin >> l >> r;
		scanf("%i %i", &l, &r);
		l--;
	}
};

bool cmp(qry a, qry b) {
	if(a.l / bs != b.l / bs) {
		return a.l / bs < b.l / bs;
	} else {
		return a.r < b.r;
	}
}

qry qries[ms];

int main() {
	std::cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		//std::cin >> a[i];
		scanf("%lli", a + i);
	}
	for(int i = 1; i <= n; i++) {
		//std::cin >> b[i];
		scanf("%lli", b + i);
		if(a[i] == 2) {
			b[i] = -b[i];
		}
		a[i] = a[i - 1] + b[i];
		hmm[a[i]] = i;
	}
	for(int i = 0; i <= n; i++) {
		if(hmm.count(a[i] - k)) {
			to[i] = hmm[a[i] - k];
		} else {
			to[i] = n + 1;
		}
		if(hmm.count(a[i] + k)) {
			to2[i] = hmm[a[i] + k];
		} else {
			to2[i] = n + 1;
		}
		from[i] = hmm[a[i]];
		//std::cout << a[i] << ", " << to[i] << ", " << from[i] << ", " << to2[i] << "\n";
	}
	int l = 0, r = -1;
	int q;
	std::cin >> q;
	for(int i = 0; i < q; i++) {
		qries[i].read(i);
	}
	ll cur = 0;
	std::sort(qries, qries + q, cmp);
	for(int i = 0; i < q; i++) {
		//std::cout << "qry (" << qries[i].l << ", " << qries[i].r << ")\n";
		while(r < qries[i].r) {
			cur += freq[to[++r]];
			freq[from[r]]++;
		}
		while(l > qries[i].l) {
			cur += freq[to2[--l]];
			freq[from[l]]++;
		}
		while(r > qries[i].r) {
			freq[from[r]]--;
			cur -= freq[to[r--]];
		}
		while(l < qries[i].l) {
			freq[from[l]]--;
			cur -= freq[to2[l++]];
		}
		ans[qries[i].idx] = cur;
		//std::cout << "got " << cur << "\n";
	}
	for(int i = 0; i < q; i++) {
		//std::cout << ans[i] << '\n';
		printf("%lli\n", ans[i]);
	}
}