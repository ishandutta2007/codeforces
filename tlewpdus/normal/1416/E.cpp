#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; // 1000000007

typedef pair<pll,ll> plll;

int n;
int A[500100];
ll val;
set<pll> se;

const pll NOP = {-LINF,-LINF-123};

pll isin(ll x) {
	auto it = se.upper_bound({x,LINF});
	if (it==se.begin()) return NOP;
	if (prev(it)->first <= x && x <= prev(it)->second) return *prev(it);
	return NOP;
}
void m1(ll x) {
	pll tmp = isin(x);
	if (tmp==NOP) {
		se.insert({x,x});
	}
	else {
		val--;
		se.clear();
		se.insert({x,x});
	}
}

void print() {
//	auto it = se.begin();
//	printf("minv : %lld\n",val);
//	while(it!=se.end()) {
//		printf("%lld %lld\n",it->first,it->second);
//		it++;
//	}
//	puts("");
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&A[i]);
		}
		se.clear();
		ll l = 0, r = A[1];
		if (A[1]%2==0) {
			val = -1;
			se.insert({A[1]/2,A[1]/2});
		}
		else {
			val = 0;
			se.insert({1,A[1]-1});
		}
		for (int i=2;i<=n;i++) {
			print();
			if (l<r) {
				l = r;
				r = l-A[i];
				auto it = se.begin();
				while(it!=se.end()) {
					if (it->second<=r) {
						it++;
						se.erase(prev(it));
					}
					else if (it->first<=r) {
						pll tmp = *it;
						se.erase(it);
						se.insert({r+1,tmp.second});
						break;
					}
					else break;
				}
				if (se.empty()) {
					se.insert({r+1,l-1});
					val++;
				}
				if (A[i]%2==0) {
					m1(r+A[i]/2);
				}
			}
			else {
				l = r;
				r = l+A[i];
				auto it = se.end();
				while(it!=se.begin()) {
					it--;
					if (it->first>=r) {
						it++;
						se.erase(prev(it));
					}
					else if (it->second>=r) {
						pll tmp = *it;
						se.erase(it);
						se.insert({tmp.first,r-1});
						break;
					}
					else break;
				}
				if (se.empty()) {
					se.insert({l+1,r-1});
					val++;
				}
				if (A[i]%2==0) {
					m1(l+A[i]/2);
				}
			}
		}
		print();
		printf("%lld\n",val+n+1);
	}

	return 0;
}