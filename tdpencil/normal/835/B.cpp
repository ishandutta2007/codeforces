#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k; cin >> k;
	string s; cin >> s;

	vector<int> st;
	int cur =0 ;
	for(char ch : s) {
		st.push_back(ch - '0');
		cur += (ch - '0');
	}	
	sort(st.begin(), st.end());
	int changes = 0;
	for(int i = 0; i < s.size(); i++) {
		if(cur >= k)
		{
			break;
		}
		++changes;
		cur += 9 - (st[i]);
	}

	cout << changes << endl;
}