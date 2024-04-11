#include <bits/stdc++.h>
using namespace std;

const int mxN=30;
int n, x;
string c[mxN];

void qry(int x, int y, string &s) {
	cout << x << " " << y << endl;
	cin >> s;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	qry(0, 0, c[0]);
	for(int i=n-2; i>=0; --i) {
		x+=1<<i;
		qry(x, 0, c[n-1-i]);
		if(c[n-1-i]!=c[0])
			x-=1<<i;
	}
	cout << x+1 << " 1 " << x+2 << " 3";
}