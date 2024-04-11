#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q=0;
	cin >> n;
	int *a = new int[n], *cnt = new int[n+1]();
	bool *seen = new bool[n]();
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	for(int i=1; i<=n; ++i)
		if(!cnt[i])
			++q;
	cout << q << "\n";
	int j=1;
	for(int i=0; i<n; ++i) {
		while(j<=n&&cnt[j]>=1)
			++j;
		if(cnt[a[i]]>1&&(j<a[i]||seen[a[i]])) {
			--cnt[a[i]];
			++cnt[j];
			a[i]=j;
		}
		seen[a[i]]=true;
	}
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
}