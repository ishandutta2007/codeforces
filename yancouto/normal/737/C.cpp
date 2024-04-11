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

template<class num> inline void read(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;
const int N = 212345;
int oc[N], oc2[N], a[N];

int main() {
	int i, j, s;
	read(n); read(s); s--;
	for(i = 0; i < n; i++) read(a[i]);
	int wr = 0;
	int re = 0;
	if(a[s] != 0) wr++;
	swap(a[s], a[n - 1]); n--;
	for(i = 0; i < n; i++) oc[a[i]]++;
	wr += oc[0];
	//printf("oc[0] = %d wr %d\n", oc[0], wr);
	for(i = 1; i < n + 10; i++) re += max(0, oc[i] - 1);
	int ot = n - oc[0];
	int mx = 0;
	for(i = n + 10; i >= 0; i--) oc2[i] = oc[i] + oc2[i + 1];
	int best = n + (a[n] != 0);
	int re_more = re, re2 = re;
	multiset<int> ms;
	for(i = 0; i < n; i++) ms.insert(a[i]);
	int cur = 0;
	while(!ms.empty()) {
		if(*ms.begin() <= cur + 1) {
			cur = max(cur, *ms.begin());
			ms.erase(ms.begin());
			continue;
		}
		cur++;
		if(oc[0]) { oc[0]--; continue; }
		ms.erase(prev(ms.end()));
		wr++;
	}
	printf("%d\n", wr);
	//for(i = 1; i < n + 10; i++) {
	//	debug("i %d ot %d re %d re2 %d oc[0] %d wr %d\n", i, ot, re, re2, oc[0], wr);
	//	re_more -= max(0, oc[i] - 1);
	//	re2 -= max(0, oc[i] - 1);
	//	if(ot == 0) break;
	//	if(oc[i] == 0 && oc[0] == 0) ot--, wr++;
	//	//else if(oc[i] == 0 && oc[0] == 0) re--, wr++, re2--;
	//	//else if(oc[i] == 0 && oc[0] == 0) re--, wr++;
	//	else if(oc[i] == 0) oc[0]--;
	//	else ot -= (oc[i] > 0);
	//	ot -= max(0, oc[i] - 1);
	//	debug("best min=%d+%d+%d\n", wr, ot, re_more);
	//	best = min(best, wr + ot);
	//}
	//printf("%d\n", best);
}