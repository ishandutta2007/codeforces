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

int pos[256], has[256];
char word[112345], op;

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 'a'; i <= 'z'; i++) pos[i] = 1;
	int ex = 0;
	bool known = false;
	while(n--) {
		if(n == 0) break;
		scanf(" %c %s", &op, word);
		if(op == '.') {
			for(i = 0; word[i]; i++)
				pos[word[i]] = 0;
		} else if(op == '!') {
			if(known) { ex++; continue; }
			for(i = 'a'; i <= 'z'; i++) has[i] = 0;
			for(i = 0; word[i]; i++) has[word[i]] = 1;
			for(i = 'a'; i <= 'z'; i++)
				if(!has[i])
					pos[i] = 0;
		} else {
			if(known) { ex++; continue; }
			pos[word[0]] = 0;
		}
		int ct = 0;
		for(i = 'a'; i <= 'z'; i++) ct += pos[i];
		known = (ct == 1);
	}
	printf("%d\n", ex);
}