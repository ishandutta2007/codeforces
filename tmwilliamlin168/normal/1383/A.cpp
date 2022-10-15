#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		bool ok=1;
		for(int i=0; i<n; ++i)
			ok&=s[i]<=t[i];
		if(!ok) {
			cout << "-1\n";
			continue;
		}
		int ans=0;
		for(int i=0; i<20; ++i) {
			int j=20;
			for(int k=0; k<n; ++k)
				if(s[k]-'a'==i&&t[k]-'a'>i)
					j=min(t[k]-'a', j);
			if(j<20) {
				for(int k=0; k<n; ++k)
					if(s[k]-'a'==i&&t[k]-'a'>i)
						s[k]='a'+j;
				++ans;
			}
		}
		cout << ans << "\n";
	}
}