#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, nxt[mxN];
ll a[mxN+1];
vector<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i+1];
		a[i+1]+=a[i];
	}
	st={n};
	for(int i=n-1; ~i; --i) {
		while(st.size()>=2&&(a[st.back()]-a[i])*(st[st.size()-2]-i)>=(a[st[st.size()-2]]-a[i])*(st.back()-i))
			st.pop_back();
		nxt[i]=st.back();
		//cout << i << " " << nxt[i] << endl;
		st.push_back(i);
	}
	cout << fixed << setprecision(9);
	for(int i=0; i<n; i=nxt[i]) {
		for(int j=i; j<nxt[i]; ++j)
			cout << (double)(a[nxt[i]]-a[i])/(nxt[i]-i) << "\n";
	}
}