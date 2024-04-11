#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, c[mxN+1];
bool b[mxN+1];
ll ans;
vector<int> v[mxN+1], st;

void av(int x, int y) {
	for(int i=0; i<1<<v[x].size(); ++i) {
		int k=1;
		for(int j=0; j<v[x].size(); ++j)
			if(i>>j&1)
				k*=v[x][j];
		c[k]+=y;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0, ai; i<n; ++i) {
		cin >> ai, b[ai]=1;
		ans=max(ans, (ll)ai);
	}
	for(int i=2; i<=mxN; ++i)
		if(!v[i].size())
			for(int j=0; (j+=i)<=mxN; )
				v[j].push_back(i);
	for(int g=1; g<=mxN; ++g) {
		for(int x=mxN/g; x; --x) {
			if(!b[x*g])
				continue;
			while(1) {
				int tc=0;
				for(int i=0; i<1<<v[x].size(); ++i) {
					int k=1;
					for(int j=0; j<v[x].size(); ++j)
						if(i>>j&1)
							k*=v[x][j];
					tc+=c[k]*(1-__builtin_popcount(i)%2*2);
				}
				if(!tc)
					break;
				if(__gcd(st.back(), x)<2)
					ans=max((ll)g*x*st.back(), ans);
				av(st.back(), -1);
				st.pop_back();
			}
			av(x, 1);
			st.push_back(x);
		}
		while(st.size()) {
			av(st.back(), -1);
			st.pop_back();
		}
	}
	cout << ans;
}