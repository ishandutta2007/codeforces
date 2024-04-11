#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define pb push_back
#define ar array
string x;
int v;
int hsh(const string c) {
	int st=1;
	for (char ch: c) {
		st=(st+(ch-'a'+1))*29;
	}
	return st;
}

void run_case() {
	map<int, int> mp;
	int n;
	cin >> n;
	array<vector<int>, 3> a;
	a.fill(vector<int>(n));
	for(int i=0;i<3;i++) {
		for(int j=0;j<n;j++) {
			cin >> x;
			v=hsh(x);
			mp[v]++;
			a[i][j]=v;
		}
	}
	array<int, 3> pts;
	pts.fill(0);

	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++) {
			if(mp[a[i][j]]==1) pts[i]+=3;
			else if(mp[a[i][j]]==2) pts[i]++;
		}
	for (int i=0;i<3;i++)
		cout << pts[i] << " ";
	cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
		run_case();
	}
}