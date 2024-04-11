#include <bits/stdc++.h>
using namespace std;

int main() {
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	cout << 3 << "\n";
	cout << bx+(ax-cx) << " " << by+(ay-cy) << "\n";
	cout << bx+(cx-ax) << " " << by+(cy-ay) << "\n";
	cout << cx+(ax-bx) << " " << cy+(ay-by) << "\n";
}