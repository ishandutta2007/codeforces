#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=1e9+7;
string s;
int n, d;
ll dp0[mxN+1], dp1[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n=s.size();
	while(n&&s[n-1]&1^1)
		--n;
	if(!n) {
		cout << s.size();
		return 0;
	}
	while(s[d]&1^1)
		++d;
	ll a=0, b=0;
	vector<ar<int, 2>> st;
	for(int i=n-1; i>=d; --i) {
		if(s[i]&1) {
			a=(a+dp0[i+1]+1)%M;
		} else {
			ar<int, 2> c{i+1, 0};
			if(st.size()&&i+1==st.back()[0]) {
				c=st.back();
				st.pop_back();
			}
			--c[0];
			++c[1];
			if(st.size()) {
				b=(b+M-dp1[st.back()[0]+1])%M;
				if(st.back()[1]<=c[1])
					st.pop_back();
			}
			st.push_back(c);
			b=(b+dp1[c[0]+1])%M;
		}
		dp0[i]=b;
		dp1[i]=a;
	}
	cout << dp1[d]*(s.size()-n+1)%M*(d+1)%M;
}