#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, q;
map<string, int> mp;
vector<int> p;

int find(int x) {
	return x^p[x]?p[x]=find(p[x]):x;
}

void join(int x, int y) {
	p[find(x)]=find(y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		mp[s]=i;
	}
	p=vector<int>(2*n);
	iota(p.begin(), p.end(), 0);
	while(m--) {
		int t;
		cin >> t;
		string s1, s2;
		cin >> s1 >> s2;
		int u=mp[s1], v=mp[s2];
		bool bd=0;
		if(t==1) {
			if(find(2*u)==find(2*v+1)) {
				bd=1;
			} else
				join(2*u, 2*v), join(2*u+1, 2*v+1);
		} else {
			if(find(2*u)==find(2*v))
				bd=1;
			else
				join(2*u, 2*v+1), join(2*u+1, 2*v);
		}
		cout << (bd?"NO":"YES") << "\n";
	}
	while(q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int u=mp[s1], v=mp[s2];
		if(find(2*u)==find(2*v))
			cout << "1\n";
		else if(find(2*u+1)==find(2*v))
			cout << "2\n";
		else
			cout << "3\n";
	}
}