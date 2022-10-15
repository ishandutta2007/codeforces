#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	set<int> st;
	cin >> n;
	for(int i(0); i < n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	for(;;) {
		int x(*st.rbegin());
		st.erase(x);
		int tmp(x / 2);
		while(tmp >= 1 && st.count(tmp) == 1) {
			tmp /= 2;
		}
		if(tmp == 0) {
			st.insert(x);
			break;
		}
		st.insert(tmp);
	}
	for(auto i : st) {
		printf("%d%c", i, i == *st.rbegin() ? '\n' : ' ');
	}
}