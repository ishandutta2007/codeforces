#include <bits/stdc++.h>
using namespace std;

int cnt[256];

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	for (char ch: c) cnt[ch]++; 
	for (char ch : a) cnt[ch]--;
	for (char ch : b) cnt[ch]--;
	if (*min_element(cnt, cnt + 256) < 0 ||
		*max_element(cnt, cnt + 256) > 0) cout << "NO\n";
	else cout << "YES\n";
}