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

int main() {
	ios::sync_with_stdio(false);
	int i, j;
	string a, b;
	cin >> a >> b;
	cout << a << " " << b << '\n';
	cin >> n;
	while(n--) {
		string c, d;
		cin >> c >> d;
		if(a == c) a = d;
		else b = d;
		cout << a << " " << b << '\n';
	}
}