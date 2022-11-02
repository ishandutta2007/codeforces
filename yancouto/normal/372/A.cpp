#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

int a[512345], mt[512345];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	multiset<int> s;
	multiset<pii> ch;
	for(i = 0; i < n; i++) s.insert(a[i]);
	sort(a, a + n);
	int tot = n;
	for(i = n - 1; i >= 0; ) {
		multiset<pii> o;
		for(j = i; j >= 0 && a[j] == a[i]; j--) {
			if(*s.rbegin() >= 2 * a[i]) {
				o.insert(pii(a[i], *s.rbegin()));
				s.erase(prev(s.end()));
				s.erase(s.find(a[i])); tot--;
			} else if(!ch.empty()) {
				s.insert(ch.rbegin()->fst);
				s.erase(s.find(a[i]));
				o.insert(pii(a[i], ch.rbegin()->snd));
				ch.erase(prev(ch.end()));
			}
		}
		for(pii e : o) ch.insert(e);
		i = j;
	}
	printf("%d\n", tot);
}