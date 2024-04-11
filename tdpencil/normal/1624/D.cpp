#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ar array
int n, k;
int c[26];
string s;
int t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	while(t--) {
		cin >> n >> k;
		cin >> s;

		memset(c,0,4*26);
		for(int i=0;i<n;i++) {
			++c[s[i]-'a'];
		}

		int c1=0,c2=0;

		for(int i=0;i<26;i++) c1+=c[i]/2,c2+=c[i]&1;

		int ans=c1/k*2;
		c2 += (c1%k)*2;
		ans+=c2>=k;
		
		cout << ans << "\n";
	}
}