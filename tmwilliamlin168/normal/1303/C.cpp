#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

char a[55];
bool vis[26];

void solve() {
	string s;
	cin >> s;
	int j=27;
	memset(a, 0, sizeof(a));
	memset(vis, 0, 26);
	a[j]=s[0];
	vis[s[0]-'a']=1;
	for(int i=1; i<s.size(); ++i) {
		if(vis[s[i]-'a']) {
			if(a[j-1]==s[i]) {
				--j;
			} else if(a[j+1]==s[i]) {
				++j;
			} else {
				cout << "NO\n";
				return;
			}
		} else {
			if(!a[j-1]) {
				--j;
			} else if(!a[j+1]) {
				++j;
			} else {
				cout << "NO\n";
				return;
			}
			a[j]=s[i];
			vis[s[i]-'a']=1;
		}
	}
	int k=0;
	while(!a[k])
		++k;
	for(int i=0; i<26; ++i)
		if(!vis[i])
			a[--k]=i+'a';
	cout << "YES\n";
	for(int i=0; i<26; ++i)
		cout << a[k+i];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}