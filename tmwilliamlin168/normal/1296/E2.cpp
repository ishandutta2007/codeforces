#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a2[mxN], dp[26];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	int a1=0;
	for(int i=n-1; ~i; --i) {
		int cd=1;
		for(int j=0; j<s[i]-'a'; ++j)
			cd=max(cd, dp[j]+1);
		a1=max(cd, a1);
		a2[i]=cd;
		dp[s[i]-'a']=cd;
	}
	cout << a1 << "\n";
	for(int i=0; i<n; ++i)
		cout << a2[i] << " ";
}