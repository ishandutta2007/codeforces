#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int main() {
	cin.sync_with_stdio(0);
	cout << fixed << setprecision(15);

	ll a, b, i = 0;
	cin >> a >> b;

	if (a < b) swap(a, b);

	while (b) {
		ll c = a % b;
		i += a / b;
		a = b;
		b = c;
	}

	cout << i << endl;
	return 0;
}