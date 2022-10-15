#include <bits/stdc++.h>
using namespace std;

const int mxN=300;
int n, m, s[2][mxN], ts[2], t[2][mxN];
string a[mxN][mxN], b[mxN][mxN];
vector<array<int, 4>> ops;
vector<char> d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> a[i][j];
			reverse(a[i][j].begin(), a[i][j].end());
			if(!i||!j)
				d.insert(d.end(), a[i][j].begin(), a[i][j].end());
			for(char c : a[i][j]) {
				if(!i||!j) {
					if(i||j)
						ops.push_back({i, j, 0, 0});
					++ts[c-'0'];
				} else if(c=='0') {
					ops.push_back({i, j, i, 0});
					++s[0][i];
				} else {
					ops.push_back({i, j, 0, j});
					++s[1][j];
				}
			}
		}
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> b[i][j];
			reverse(b[i][j].begin(), b[i][j].end());
			if(i&&j) {
				for(char c : b[i][j]) {
					if(c=='0')
						++t[0][i];
					else
						++t[1][j];
				}
			}
		}
	}
	int at1=1, at2=1;
	for(char c : d) {
		if(c=='0') {
			while(at1<n-1&&s[0][at1]>=t[0][at1])
				++at1;
			ops.push_back({0, 0, at1, 0});
			++s[0][at1];
		} else {
			while(at2<m-1&&s[1][at2]>=t[1][at2])
				++at2;
			ops.push_back({0, 0, 0, at2});
			++s[1][at2];
		}
	}
	for(int i=1; i<n-1; ++i) {
		while(s[0][i]>t[0][i]) {
			while(at1<n-1&&s[0][at1]>=t[0][at1])
				++at1;
			ops.push_back({i, 0, at1, 0});
			--s[0][i];
			++s[0][at1];
		}
	}
	for(int i=1; i<m-1; ++i) {
		while(s[1][i]>t[1][i]) {
			while(at2<m-1&&s[1][at2]>=t[1][at2])
				++at2;
			ops.push_back({0, i, 0, at2});
			--s[1][i];
			++s[1][at2];
		}
	}
	for(int i=1; i<n; ++i) {
		for(int j=1; j<m; ++j) {
			for(char c : b[i][j]) {
				if(c=='0') {
					ops.push_back({i, 0, i, j});
					--s[0][i];
				} else {
					ops.push_back({0, j, i, j});
					--s[1][j];
				}
			}
		}
	}
	for(int i=1; i<n; ++i) {
		for(char c : b[i][0]) {
			if(c=='0') {
				ops.push_back({n-1, 0, 0, 0});
				ops.push_back({0, 0, i, 0});
			} else {
				ops.push_back({0, m-1, 0, 0});
				ops.push_back({0, 0, i, 0});
			}
		}
	}
	for(int i=1; i<m; ++i) {
		for(char c : b[0][i]) {
			if(c=='0') {
				ops.push_back({n-1, 0, 0, 0});
				ops.push_back({0, 0, 0, i});
			} else {
				ops.push_back({0, m-1, 0, 0});
				ops.push_back({0, 0, 0, i});
			}
		}
	}
	for(char c : b[0][0]) {
		if(c=='0')
			ops.push_back({n-1, 0, 0, 0});
		else
			ops.push_back({0, m-1, 0, 0});
	}
	cout << ops.size() << "\n";
	for(array<int, 4> a : ops)
		cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " " << a[3]+1 << "\n";
}