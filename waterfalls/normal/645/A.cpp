#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b,c,d;
	cin >> a >> c >> b >> d;
	a = a+c[1]+c[0];
	b = b+d[1]+d[0];
	a.erase(a.begin()+a.find('X'));
	b.erase(b.begin()+b.find('X'));
	for (int i=0;i<3;i++) {
		if (a==b) return (cout << "YES"), 0;
		rotate(&a[0],&a[1],&a[3]);
	}
	cout << "NO";

    return 0;
}