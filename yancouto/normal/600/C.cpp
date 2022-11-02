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

char ss[200009];
int c[26];
int main() {
	int i;
	scanf("%s", ss);
	for(i = 0; ss[i]; i++)
		c[ss[i] - 'a']++;
	deque<int> odd;
	for(i = 0; i < 26; i++)
		if(c[i] & 1)
			odd.pb(i);
	while(odd.size() > 1) {
		c[odd.front()]++;
		c[odd.back()]--;
		odd.pop_front();
		odd.pop_back();
	}
	string s;
	for(i = 0; i < 26; i++)
		s.append(c[i] / 2, 'a' + i);
	if(!odd.empty()) s.append(1, 'a' + odd.front());
	for(i = 25; i >= 0; i--)
		s.append(c[i] / 2, 'a' + i);
	printf("%s\n", s.c_str());
}