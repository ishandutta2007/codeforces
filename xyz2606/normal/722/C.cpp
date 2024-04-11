#include<bits/stdc++.h>
using namespace std;
const int N(111111);
int n;
long long a[N], s[N], mn[N * 4], mx[N * 4];
void build(int k, int le, int ri) {
	mx[k] = 0;
	mn[k] = n + 1;
	if(le == ri) {
		
	}else {
		int mid(le + ri >> 1);
		build(k + k, le, mid);
		build(k + k + 1, mid + 1, ri);
	}
}
long long getMin(int k, int le, int ri, int qle, int qri) {
	if(qle <= le && ri <= qri) {
		return mn[k];
	}else {
		int mid(le + ri >> 1);
		long long res(n + 1);
		if(qle <= mid) {
			res = min(res, getMin(k + k, le, mid, qle, qri));
		}
		if(qri >= mid + 1) {
			res = min(res, getMin(k + k + 1, mid + 1, ri, qle, qri));
		}
		return res;
	}
}
long long getMax(int k, int le, int ri, int qle, int qri) {
	if(qle <= le && ri <= qri) {
		return mx[k];
	}else {
		int mid(le + ri >> 1);
		long long res(0);
		if(qle <= mid) {
			res = max(res, getMax(k + k, le, mid, qle, qri));
		}
		if(qri >= mid + 1) {
			res = max(res, getMax(k + k + 1, mid + 1, ri, qle, qri));
		}
		return res;
	}
}
void renew(int k, int le, int ri, int qposi, int qx) {
	if(le == ri) {
		mn[k] = qx;
		mx[k] = qx;
	}else {
		int mid(le + ri >> 1);
		if(qposi <= mid) {
			renew(k + k, le, mid, qposi, qx);
		}else {
			renew(k + k + 1, mid + 1, ri, qposi, qx);
		}
		mn[k] = min(mn[k + k], mn[k + k + 1]);
		mx[k] = max(mx[k + k], mx[k + k + 1]);
	}
}
int main() {
	cin >> n;
	for(int i(1); i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	multiset<long long> st;
	st.insert(s[n]);
	build(1, 1, n);
	for(int i(1); i <= n; i++) {
		int id;
		cin >> id;
		//printf("??");
		int le(id == 1 ? 0 : getMax(1, 1, n, 1, id - 1));
		//printf("??");
		int ri(id == n ? n + 1 : getMin(1, 1, n, id + 1, n));
		//printf("??");
		//printf("%d %d\n", le, ri);
		st.erase(st.find(s[ri - 1] - s[le]));
		//printf("+%d %d\n", s[id - 1] - s[le], s[ri - 1] - s[id]);
		st.insert(s[id - 1] - s[le]);
		st.insert(s[ri - 1] - s[id]);
		renew(1, 1, n, id, id);
		//printf("~\n");
		printf("%I64d\n", *st.rbegin());
	}
}