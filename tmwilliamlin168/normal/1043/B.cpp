#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define array a

const int mxN=1e3;
int n, a[mxN+1], b[mxN];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		if(i)
			b[i-1]=a[i]-a[i-1];
	}
	for(int i=1; i<=n; ++i) {
		bool ok=1;
		for(int j=0; j+i<n&&ok; ++j)
			ok=b[j]==b[j+i];
		if(ok)
			ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for(int ai : ans)
		cout << ai << " ";
}