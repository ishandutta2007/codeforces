
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
string t, s;

void solve() {
	cin >> t;
	int p = find(t.begin(), t.end(), '|') - t.begin();
	cin >> s;

	int onLeft = p;
	int onRight = t.size() - p - 1;
	string x = t.substr(0, p);
	string y = t.substr(p+1);
	for(auto ch : s) {
		if(x.size() < y.size()) x += ch;
		else y += ch;
	}

	if(x.size() == y.size()) {
		cout << x + "|" + y << "\n";
	} else {
		cout << "Impossible\n";
	}

	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	//cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}