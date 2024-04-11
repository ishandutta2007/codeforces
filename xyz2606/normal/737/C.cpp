#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	int ans(0);
	multiset<int> st;
	int cnt0(0);
	for(int i(1); i <= n; i++) {
		int x;
		scanf("%d", &x);

		if(i != s) {
			if(x != 0) 
				st.insert(x);
			else {
				cnt0++;
			}
		}else {
			ans += x != 0;
		}
	}
	ans += cnt0;
	if(st.size()) {
		int i(1);
		for(;*st.rbegin() > i;) {
			if(st.count(i) == 0) {
				if(cnt0) {
					st.insert(i);
					cnt0--;
				}else {
					auto itr(st.find(*st.rbegin()));
					st.erase(itr);
					st.insert(i);
					ans++;
				}
			}
			i++;
		}
	}
	cout << ans << endl;
}