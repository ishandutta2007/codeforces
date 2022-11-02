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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
char s[112345];

int main() {
	scanf("%s", s);
	n = strlen(s);
	int cA = 0, cB = 0, cC = 0;
	int i;
	for(i = 0; i < n && s[i] == 'a'; i++) cA++;
	for(; i < n && s[i] == 'b'; i++) cB++;
	for(; i < n && s[i] == 'c'; i++) cC++;
	if(i == n && cA > 0 && cB > 0 && (cC == cA || cC == cB)) puts("YES");
	else puts("NO");
}