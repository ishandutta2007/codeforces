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
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

void end(int x) {
	printf("YES\n%d\n", x);
	exit(0);
}

int n[1123];
char s[1123];
int main() {
	int i, j, k;
	scanf("%s", s);
	for(i = 0; s[i]; i++) n[i] = s[i] - '0';
	for(i = 0; s[i]; i++)
		if(!(n[i] % 8)) end(n[i]);
	for(i = 0; s[i]; i++)
		for(j = i + 1; s[j]; j++) {
			int x = 10*n[i] + n[j];
			if(!(x % 8)) end(x);
		}
	for(i = 0; s[i]; i++)
		for(j = i + 1; s[j]; j++)
			for(k = j + 1; s[k]; k++) {
				int x = 100*n[i] + 10*n[j] + n[k];
				if(!(x % 8)) end(x);
			}
	puts("NO");
}