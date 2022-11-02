#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>

#define mp make_pair
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';dbgx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define dbg(...)(cerr<<"<"<<__LINE__,dbgx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define dbg(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void dbgx(...){}TM void dbgx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;dbgx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

int n, q;

struct Tree {
	vector<double> mults, adds, sums;
	int len{1};

	DD(len, mults, adds, sums);

	Tree(int k) {
		while (len < k) len *= 2;
		mults.resize(len*2, 0);
		adds.resize(len*2, 0);
		sums.resize(len*2, 0);
	}

	void apply(int i, int size, double mult, double add) {
		mults[i] *= mult;
		adds[i] = adds[i]*mult + add;
		sums[i] = sums[i]*mult + add*size;
	}

	void modify(int vBegin, int vEnd, double mult, double add, int i = 1, int begin = 0, int end = -1) {
		if (end < 0) end = len;
		if (vBegin >= end || vEnd <= begin) return;

		if (begin >= vBegin && end <= vEnd) {
			apply(i, end-begin, mult, add);
			return;
		}

		int mid = (begin+end) / 2;
		int l = i*2, r = i*2+1;

		apply(l, mid-begin, mults[i], adds[i]);
		apply(r, end-mid, mults[i], adds[i]);
		mults[i] = 1;
		adds[i] = 0;

		modify(vBegin, vEnd, mult, add, l, begin, mid);
		modify(vBegin, vEnd, mult, add, r, mid, end);
		sums[i] = sums[l] + sums[r];
	}

	double sum(int vBegin, int vEnd, int i = 1, int begin = 0, int end = -1) {
		if (end < 0) end = len;
		if (vBegin >= end || vEnd <= begin) return 0;

		if (begin >= vBegin && end <= vEnd) {
			return sums[i];
		}

		int mid = (begin+end) / 2;
		int l = i*2, r = i*2+1;

		apply(l, mid-begin, mults[i], adds[i]);
		apply(r, end-mid, mults[i], adds[i]);
		mults[i] = 1;
		adds[i] = 0;

		return sum(vBegin, vEnd, l, begin, mid) + sum(vBegin, vEnd, r, mid, end);
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> q;
	Tree tree(n);

	rep(i, 0, n) {
		int tmp; cin >> tmp;
		tree.modify(i, i+1, 0, tmp);
	}

	dbg(tree);

	while (q--) {
		int mode; cin >> mode;

		if (mode == 1) {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--; l2--;

			double d1 = r1-l1, d2 = r2-l2;
			double v1 = tree.sum(l1, r1), v2 = tree.sum(l2, r2);

			tree.modify(l1, r1, (d1-1)/d1, v2/d1/d2);
			tree.modify(l2, r2, (d2-1)/d2, v1/d1/d2);
		} else {
			int l, r; cin >> l >> r;
			l--;

			cout << tree.sum(l, r) << endl;
		}
	}
	return 0;
}