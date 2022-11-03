#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int Case, n, a[N];
int main() {
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}
		set<int> st;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				st.insert(a[j] - a[i]);
		cout << st.size() << endl;
	}
	return 0;
}