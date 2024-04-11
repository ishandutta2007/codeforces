#include <bits/stdc++.h>
#define REP(i, a) for(int i = 0; i < a; i++)
#define LP(x, y) for(auto x : y)
#define ll long long
using namespace std;
void prti(int i) {
	cout << i << '\n';
}
void prts(string s) {
	cout << s << '\n';
}

ll prtl(ll x) {
	cout << x << '\n';
}
int read() {
	int b; cin >> b;
	return b;
}
int main() {
	ll x, y=0;
	cin>>x;
	if(x%2) {
		y=-x/2-1;
		prtl(y);
	}
	else prtl(x/2);
}