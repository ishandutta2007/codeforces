#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
char s1[200009], s2[200009];
int n;

void small(int s, int e, char *st) {
	if((e - s + 1) & 1) return;
	int mid = (s + e) / 2;
	small(s, mid, st); small(mid + 1, e, st);
	if(strncmp(st + s, st + mid + 1, mid - s + 1) > 0)
		for(int i = s; i <= mid; i++)
			swap(st[i], st[i - s + mid + 1]);
}


int main() {
	int i, j;
	scanf(" %s %s", s1, s2);
	n = strlen(s1);
	small(0, n - 1, s1);
	small(0, n - 1, s2);
	if(strcmp(s1, s2) == 0) puts("YES");
	else puts("NO");
	return 0;
}