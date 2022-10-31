#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, a[200009], has[200009];
bool ok(int i) {
	if(i == n - 1 || i < 0) return true;
	if(i & 1) return a[i] > a[i + 1];
	else return a[i] < a[i + 1];
}

int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int w = 0, nd = 0;
	vector<int> pos, obs;
	int seq = 0;
	for(i = 0; i < n - 1; i++) {
		if(!ok(i)) seq++;
		else nd += (seq + 1) / 2, seq = 0;
		if(!ok(i) && ok(i - 1) && i) obs.pb(i - 1);
		if(!ok(i) && (pos.empty() || pos.back() != i)) pos.pb(i);
		if(!ok(i)) w++, pos.pb(i + 1), obs.pb(i);
	}
	for(int x : pos) has[x] = true;
	nd += (seq + 1) / 2;
	if(nd > 2) { puts("0"); return 0; }
	int tot= 0;
	if(nd == 2) {
		for(i = 0; i < pos.size(); i++)
			for(j = i + 1; j < pos.size(); j++) {
				swap(a[pos[i]], a[pos[j]]);
				for(k = 0; k < obs.size() && ok(obs[k]); k++);
				if(k == obs.size()) tot++;
				swap(a[pos[i]], a[pos[j]]);
			}
	} else {
		for(i = 0; i < n; i++)
			if(!has[i])
				for(j = 0; j < pos.size(); j++) {
					if(i > pos[j]) continue;
					swap(a[i], a[pos[j]]);
					for(k = 0; k < obs.size() && ok(obs[k]); k++);
					if(k == obs.size() && ok(i) && ok(i - 1)) tot++;
					swap(a[i], a[pos[j]]);
				}

		for(j = 0; j < pos.size(); j++)
			for(i = 0; i < n; i++) {
				if(pos[j] > i) continue;
				swap(a[i], a[pos[j]]);
				for(k = 0; k < obs.size() && ok(obs[k]); k++);
				if(k == obs.size() && ok(i) && ok(i - 1)) tot++;
				swap(a[i], a[pos[j]]);
			}
	}
	printf("%d\n", tot);
}