#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int x1 , y1  , x2 , y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int now = 0;
	if(x1 == x2) now += 2;
	if(y1 == y2) now += 2;
	cout <<now + 4 + 2 * abs(x1 - x2) + 2 * abs(y1 - y2) << endl;
}