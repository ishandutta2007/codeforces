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
char s[212345];

int main() {
	int i, j, ct = 0;
	scanf("%d %s", &n, s);
	for(i = 0; i < n && s[i] == '<'; i++, ct++);
	for(i = n - 1; i >= 0 && s[i] == '>'; i--, ct++);
	printf("%d\n", ct);
}