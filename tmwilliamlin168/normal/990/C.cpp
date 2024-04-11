#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=3e5;
int n;
ll ans, cnt1[mxN+1], cnt2[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		int b=0, mb=0;
		for(int j=0; j<s.size()&&!mb; ++j) {
			b+=s[j]=='('?1:-1;
			mb=min(b, mb);
		}
		if(!mb)
			++cnt1[b];
		b=mb=0;
		for(int j=s.size()-1; j>=0&&!mb; --j) {
			b+=s[j]==')'?1:-1;
			mb=min(b, mb);
		}
		if(!mb)
			++cnt2[b];
	}
	for(int i=0; i<=mxN; ++i)
		ans+=cnt1[i]*cnt2[i];
	cout << ans;
}