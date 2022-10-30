#include <bits/stdc++.h>
using namespace std;

string s;
string t = "Bulbasaur";
int has[200], need[200];

int main() {
	cin >> s;
	for (char c: s) has[c]+=1;
	for (char c: t) need[c]+=1;
	int ans = 1e9;
	for (char c: t) ans = min(ans,has[c]/need[c]);
	cout << ans << endl;

	return 0;
}