#include <bits/stdc++.h>
using namespace std;

int a[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(char c : s)
		++a[c-'A'];
	int ans=INT_MAX;
	for(int i=0; i<k; ++i)
		ans=min(a[i], ans);
	cout << ans*k;
}