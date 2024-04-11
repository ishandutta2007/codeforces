#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define bi int64_t
#define IN bi(1e9)
#define si(i) bi(i.size())

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	a.append(b);
	if(a.size()!=c.size()) {
		cout << "NO";
		return 0;
	}
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	bool ok = true;
	for(int i =0 ; i < a.size(); i++) {
		if(a[i]!=c[i]) ok = false;
	}
	cout << (ok ? "YES" : "NO");
	return 0;
}