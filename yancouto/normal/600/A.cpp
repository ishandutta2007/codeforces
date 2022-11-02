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

bool is_num(char *c) {
	if(c[0] == 0) return false;
	if(c[1] == 0 && c[0] == '0') return true;
	if(c[0] > '9' || c[0] < '1') return false;
	for(int i = 1; c[i]; i++)
		if(!isdigit(c[i]))
			return false;
	return true;
}

void add_to(string &s, bool &has, char *c) {
	if(has) s.append(",");
	s.append(c);
	has = true;
}

char s[100009];
int main() {
	scanf("%s", s);
	string a, b;
	bool hasa = false, hasb = false;
	char *c = s;
	while(true) {
		char *d = c;
		while(*d && *d != ';' && *d != ',') d++;
		bool end = (*d == 0);
		*d = 0;
		if(is_num(c)) add_to(a, hasa, c);
		else add_to(b, hasb, c);
		c = d + 1;
		if(end) break;
	}
	if(hasa) printf("\"%s\"\n", a.c_str());
	else printf("-\n");
	if(hasb) printf("\"%s\"\n", b.c_str());
	else printf("-\n");
}