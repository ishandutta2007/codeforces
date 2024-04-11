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
char s[112345];
int oc[256];

int main() {
	int i, j;
	scanf("%s", s);
	for(i = 0; s[i]; i++) oc[s[i]]++;
	int tot = 0;
	while(true) {
		bool all = true;
		for(char c : "Bulbasaur") {
			if(!isalpha(c)) break;
			if(oc[c]) oc[c]--;
			else { all = false; }
		}
		if(all) tot++;
		else break;
	}
	printf("%d\n", tot);
}