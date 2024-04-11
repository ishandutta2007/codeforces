#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pii tA;
typedef int tB;
typedef tree<tA, tB, greater<tA>, rb_tree_tag, tree_order_statistics_node_update> ord_set;
// map: tA -> tB com comparador less<tA>
// pode usar como um map normalmente
// s.find_by_order(k) :: retorna iterador para o k-esimo elemento (0-index) (ou s.end())
// s.order_of_key(x)  :: retorna a qtd de elementos estritamente menores que x


template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n, k;
const int N = 312345;
int p[N];
vector<pii> v;

int main() {
	int i, j, l, r;
	rd(n); rd(k);
	for(i = 0; i < n; i++) {
		rd(l); rd(r);
		v.pb(pii(l, r));
		p[i] = i;
	}
	sort(p, p + n, [](int i, int j) { return v[i] < v[j]; });
	ord_set s;
	int best = 0, st = INT_MAX;
	for(i = 0; i < n; i++) {
		pii p = v[::p[i]];
		s[pii(p.snd, i)] = 0;
		if((int)s.size() < k) continue;
		int R = s.find_by_order(k - 1)->fst.fst;
		if(R - p.fst + 1 >= best) {
			st = p.fst;
			best = R - p.fst + 1;
		}
	}
	printf("%d\n", best);
	v.clear();
	vector<int> ans;
	for(i = 0; i < n; i++)
		if(v[i].fst <= st)
			ans.pb(i);
	sort(ans.begin(), ans.end(), [](int i, int j) { return v[i].snd > v[j].snd; });
	assert((int)ans.size() >= k);
	for(i = 0; i < k; i++)
		printf("%d ", ans[i] + 1);
	putchar('\n');
}