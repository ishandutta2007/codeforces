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

string nm[100];
char tmp[100];

bool get() {
	scanf("%s", tmp);
	return tmp[0] == 'Y';
}

int en = 0;
string v[100];

int main() {
	int i, j, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < 100; i++)
		for(j = 0; j < 10; j++)
			nm[i] += char('a' + ((i >> j) & 1));
	for(i = 0; i < 100; i++) nm[i][0] = toupper(nm[i][0]);
	for(i = 0; i < k - 1; i++) v[i] = nm[en++];
	for(i = 0; i < n - k + 1; i++)
		if(get())
			v[i + k - 1] = nm[en++];
		else
			v[i + k - 1] = v[i];
	for(i = 0; i < n; i++)
		printf("%s ", v[i].c_str());
	putchar('\n');
}