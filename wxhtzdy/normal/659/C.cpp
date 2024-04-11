#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, a[mxN];

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a,a+n);
	vector<int> ans;
	int nxt=1, j=0;
	while(m>=nxt) {
		if(j<n&&a[j]==nxt) {
			++nxt, ++j;
			continue;
		}
		ans.push_back(nxt);
		m-=nxt;
		++nxt;
	}
	cout << (int) ans.size() << '\n';
	for(int c:ans)
		cout << c << " ";
	return 0;
}