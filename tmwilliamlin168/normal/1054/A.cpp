#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int a=abs(x-y)*t1, b=(abs(x-y)+abs(x-z))*t2+3*t3;
	cout << (b<=a?"YES":"NO");
}