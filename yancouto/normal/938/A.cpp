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

char s[112345];
int vowel[256];

int main() {
	for(char c : "aeiouy")
		vowel[c] = 1;
	int n;
	int i, j;
	scanf("%d %s", &n, s);
	string ans;
	for(i = 0; i < n; i++)
		if(!i || !vowel[s[i]] || !vowel[s[i - 1]])
			ans.pb(s[i]);
	cout << ans << endl;
}