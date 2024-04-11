#include<set>
#include<map>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 100005;
int a[N];

struct Block {
	int len, st, ed, num;

	Block(const int len = 0, const int st = 0, const int ed = 0, const int num = 0) : len(len), st(st), ed(ed), num(num) {};

};

vector<Block> v;

bool islucky(int a) {
	bool ret = true;
	while (a && ret) {
		ret = a % 10 == 4 || a % 10 == 7;
		a /= 10;
	}
	return ret;
}

typedef unsigned long long ull;

struct Node {
	int l, r;
	Node *left, *right;

	Node(const int l = 0, const int r = 0) : l(l), r(r), left(NULL), right(NULL) {}
		
};

ull cal(const ull l, const ull r) {
	return (r - l) * (r - l + 1) / 2;
}

ull cal3(const ull n) {
	return n * (n + 1) / 2 * n * (n + 1) / 2;
}

ull cal3(const ull l, const ull r) {
	return (r * (r + 1) / 2 + (l - 1) * l / 2) * (r * (r + 1) / 2 - (l - 1) * l / 2);
}

ull cal2(const ull n) {
	return n * (2 * n + 1) * (n + 1) / 6;
}

ull cal2(const ull l, const ull r) {
	return cal2(r) - cal2(l - 1); 
}

ull cal1(const ull l, const ull r) {
	return (r + l) * (r - l + 1) / 2;
}

ull cal0(const ull l, const ull r) {
	return r - l + 1;
}

int main() {
	ull n;
	cin >> n;
	int last = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (islucky(a[i])) {
			v.push_back(Block(i - last + 1, last, i, a[i]));
			last = i + 1;
		}
	}
	a[n] = -1;
	if (last != n) {
		v.push_back(Block(n - last, last, n, -1));
	}
	map<int, vector<int> > tr;
	for (int i = 0; i < (int)v.size(); ++i) {
		tr[v[i].num].push_back(v[i].ed);
	}
	ull ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		ull bpSum = 0;
		set<int> bp;
		set<int> contain;
		ull tmp = 0;
		tmp = 1 * cal3(v[i].st, v[i].ed - 1);
		tmp += (n * (n - 1) + n * (v[i].st - 1) + (n - 1) * (v[i].st - 1)) * cal1(v[i].st, v[i].ed - 1); 
		tmp -= (n + n - 1 + (v[i].st - 1) ) * cal2(v[i].st, v[i].ed - 1);
		tmp -= (v[i].st - 1) * n * (n - 1) * cal0(v[i].st, v[i].ed - 1);
		ans += tmp / 2;		
		bp.insert(n);
		bp.insert(v[i].ed - 1);
		bpSum = cal(v[i].ed, n);
		for (int j = i; j + 1 < (int)v.size(); ++j) {
			int bar = v[j + 1].ed;
			while (*bp.begin() < bar) {
				bpSum -= cal(*bp.begin() + 1, *(++bp.begin()));
				bp.erase(bp.begin());
			}
			bp.insert(bar - 1);
			bpSum += cal(*bp.begin() + 1, *(++bp.begin()));
			if (!contain.count(v[j].num)) {
				contain.insert(v[j].num);
				vector<int> breaks = tr[v[j].num];
				for (int k = 0; k < breaks.size(); ++k) {
					if (breaks[k] >= v[j + 1].ed) {
						int cut = breaks[k];
						set<int>::iterator it = bp.upper_bound(cut);
						int right = *it, left = *(--it);
						bpSum -= cal(left + 1, right);
						bp.insert(cut);
						bpSum += cal(left + 1, cut) + cal(cut + 1, right);
					}
				}
			}
			ull k, tmp1, rem = bpSum;
			k = *(++bp.begin());
			rem *= (v[j + 1].ed - v[j].ed);
			tmp1 = 1 * cal2(v[j].ed, v[j + 1].ed - 1) + (2 * k - v[j + 1].ed) * (v[j + 1].ed - 1) * cal0(v[j].ed, v[j + 1].ed - 1) - (2 * k - v[j + 1].ed + v[j + 1].ed - 1) * cal1(v[j].ed, v[j + 1].ed - 1);
			ans += v[i].len * (rem + tmp1 / 2);
		}
	}
	cout << ans << endl;
	return 0;
}