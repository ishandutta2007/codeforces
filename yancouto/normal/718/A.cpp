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
	int i, j, t;
	scanf("%d %d", &n, &t);
	s[0] = '0';
	scanf("%s", s + 1);
	for(i = 1; s[i] != '.'; i++);
	for(i++; s[i] && s[i] <= '4'; i++);
	if(!s[i]) {
		puts(s + 1);
		return 0;
	}
	while(t--) {
		if(s[i] <= '4') break;
		s[i] = 0;
		for(i--; s[i] != '.'; i--) {
			if(s[i] == '9') {
				s[i] = 0;
				continue;
			}
			s[i]++;
			break;
		}
		if(s[i] == '.') {
			s[i] = 0;
			for(i--; s[i] == '9'; i--)
				s[i] = '0';
			s[i]++;
			puts(s + !!i);
			return 0;
		}
	}
	puts(s + 1);
}