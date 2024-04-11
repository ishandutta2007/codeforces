#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;

void aa(vector<int> &v, int n) {
	int x=1, y=n;
	while(x<y) {
		v.push_back(x++);
		if(x==y)
			break;
		v.push_back(y--);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int x=1, y=n;
	while(x<y) {
		int i1=1, i2=m;
		while(i1<=m) {
			cout << x << " " << i1 << "\n";
			cout << y << " " << i2 << "\n";
			++i1;
			--i2;
		}
		++x;
		--y;
	}
	if(x==y) {
		int i1=1, i2=m;
		while(i1<i2) {
			cout << x << " " << i1 << "\n";
			++i1;
			if(i1==i2)
				break;
			cout << x << " " << i2 << "\n";
			--i2;
		}
		if(i1==i2)
			cout << x << " " << i1 << "\n";
	}
}