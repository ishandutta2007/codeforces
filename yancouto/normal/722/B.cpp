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

int n;
int p[1123];
char ln[1123];
int vog[256];

int main() {
	for(char c : "aeiouy") vog[c] = 1;
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &p[i]);
	scanf(" ");
	for(i = 0; i < n; i++) {
		fgets(ln, sizeof ln, stdin);
		int ct = 0;
		for(j = 0; ln[j]; j++) ct += vog[ln[j]];
		if(ct != p[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}