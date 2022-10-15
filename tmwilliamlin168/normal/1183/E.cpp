#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string s;

struct cmp {
	bool operator()(const string &s, const string &t) const {
		return s.size()<t.size()||s.size()==t.size()&&s<t;
	}
};

set<string, cmp> a, a2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	a.insert("");
	for(int i=0; i<n; ++i) {
		a2=a;
		for(string t : a)
			a2.insert(t+s[i]);
		a=a2;
		while(a.size()>k) {
			a.erase(a.begin());
		}
	}
	//cout << a.size();
	if(a.size()<k) {
		cout << "-1\n";
		return 0;
	}
	int ans=0;
	for(string t : a)
		ans+=n-t.size();
	cout << ans;
}