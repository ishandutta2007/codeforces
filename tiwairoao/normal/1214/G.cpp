#include<cstdio>
#include<set>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 2000 + 5;
#define BITNUM 64
ull f[BITNUM];
struct bitset{
	#define SIZE 32
	ull a[SIZE], cnt;
	bitset() {
		for(int i=0;i<SIZE;i++) a[i] = 0;
	}
	void count() {
		cnt = 0;
		for(int i=0;i<SIZE;i++)
			cnt += __builtin_popcount(a[i]) + __builtin_popcount(a[i] >> 32);
	}
	friend bool operator < (const bitset &a, const bitset &b) {
		return a.cnt < b.cnt;
	}
	friend bitset operator &(const bitset &a, const bitset &b) {
		bitset c;
		for(int i=0;i<SIZE;i++)
			c.a[i] = a.a[i] & b.a[i];
		return c;
	}
	friend bitset operator ^(const bitset &a, const bitset &b) {
		bitset c;
		for(int i=0;i<SIZE;i++)
			c.a[i] = a.a[i] ^ b.a[i];
		return c;
	}
	friend bitset operator ~(const bitset &a) {
		bitset c;
		for(int i=0;i<SIZE;i++)
			c.a[i] = ~a.a[i];
		return c;
	}
	friend bool operator == (const bitset &a, const bitset &b) {
		for(int i=0;i<SIZE;i++)
			if( a.a[i] != b.a[i] )
				return false;
		return true;
	}
	friend bool operator != (const bitset &a, const bitset &b) {
		return !(a == b);
	}
	void set(ull k) {
		for(int i=0;i<SIZE;i++) {
			if( k < BITNUM ) {
				a[i] |= f[k];
				break;
			}
			else k -= BITNUM;
		}
	}
	ull bit() {
		for(int i=0;i<SIZE;i++)
			if( a[i] ) {
				int l = 0, r = BITNUM - 1;
				while( l < r ) {
					int mid = (l + r + 1) >> 1;
					if( f[mid] <= a[i] ) l = mid;
					else r = mid - 1;
				}
				return l + i*BITNUM;
			}
		puts("error");
		exit(0);
	}
};
set<pair<bitset, int> >st1;
set<pair<bitset, int> >::iterator it1, it2, it3;
set<pair<int, int> >st2;
set<pair<int, int> >::iterator it;
bitset bts[MAXN], b[MAXN];
int n, m, q;
bool check(const bitset &a, const bitset &b) {
	if( (a & b) != a && (a & b) != b )
		return true;
	else return false;
}
void init() {
	f[0] = 1;
	for(int i=1;i<BITNUM;i++)
		f[i] = f[i-1]<<1;
}
int main() {
	init();
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=m;i++)
		b[i] = b[i-1], b[i].set(i - 1), b[i].count();
	for(int i=0;i<n;i++)
		st1.insert(make_pair(bts[i], i));
	for(int i=1;i<=q;i++) {
		int a, l, r; scanf("%d%d%d", &a, &l, &r), a--;
		it1 = st1.find(make_pair(bts[a], a));
		if( it1 == st1.begin() )
			it2 = st1.end();
		else it2 = it1, it2--;
		it3 = it1, it3++;
		if( it2 != st1.end() ) {
			if( check(it2->first, it1->first) )
				st2.erase(make_pair(it2->second, a));
		}
		if( it3 != st1.end() ) {
			if( check(it1->first, it3->first) )
				st2.erase(make_pair(a, it3->second));
		}
		if( it2 != st1.end() && it3 != st1.end() ) {
			if( check(it2->first, it3->first) )
				st2.insert(make_pair(it2->second, it3->second));
		}
		st1.erase(make_pair(bts[a], a));
		bts[a] = bts[a] ^ b[r] ^ b[l - 1]; bts[a].count();
		st1.insert(make_pair(bts[a], a));
		it1 = st1.find(make_pair(bts[a], a));
		if( it1 == st1.begin() )
			it2 = st1.end();
		else it2 = it1, it2--;
		it3 = it1, it3++;
		if( it2 != st1.end() ) {
			if( check(it2->first, it1->first) )
				st2.insert(make_pair(it2->second, a));
		}
		if( it3 != st1.end() ) {
			if( check(it1->first, it3->first) )
				st2.insert(make_pair(a, it3->second));
		}
		if( it2 != st1.end() && it3 != st1.end() )
			if( check(it2->first, it3->first) )
				st2.erase(make_pair(it2->second, it3->second));
		if( st2.empty() ) {
			puts("-1");
		}
		else {
			pair<int, int> p = *st2.begin();
			int x1 = min(p.first, p.second), x2 = max(p.first, p.second);
			int y1 = (bts[p.first] & (~bts[p.second])).bit();
			int y2 = (bts[p.second] & (~bts[p.first])).bit();
			printf("%d %d %d %d\n", x1 + 1, min(y1, y2) + 1, x2 + 1, max(y1, y2) + 1);
		}
	}
}