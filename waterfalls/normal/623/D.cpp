#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct Friend {
	ld p, cur, next;
	Friend(ld pp) {
		p = 1-pp;
		cur = 0;
		next = pp;
	}
	void advance() {
		cur = next;
		next = 1-(1-next)*p;
	}
	bool operator<(const Friend o) const {
		return next/cur>o.next/o.cur;
	}
};

int n;
multiset<Friend> has;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int p;
		scanf("%d",&p);
		has.insert(Friend(p/100.));
	}
	ld ans = 0;
	ld cur = 1;
	int on = 1;
	auto start = clock();
	while ((double) (clock()-start)/CLOCKS_PER_SEC<1.9) {
		auto f = *has.begin();
		has.erase(has.begin());
		if (f.cur) cur/=f.cur;
		if (on>=n) ans+=on*cur*(f.next-f.cur);
		cur*=f.next;
		f.advance();
		has.insert(f);
		on+=1;
	}
	printf("%1.9f\n",(double) ans);

	return 0;
}