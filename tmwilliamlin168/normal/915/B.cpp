#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	bool a=l==1, b=r==n;
	if(a&&b)
		cout << 0;
	else if(a)
		cout << abs(pos-r)+1;
	else if(b)
		cout << abs(pos-l)+1;
	else
		cout << 2+r-l+min(abs(pos-r), abs(pos-l));
}