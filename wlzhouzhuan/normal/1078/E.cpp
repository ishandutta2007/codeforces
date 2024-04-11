#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
string ans;
void repeat(string x, int cnt) {
	while (cnt--) ans += x;
}
void setx(int x) {
	repeat("l", 50);
	repeat("lt", 55);
	repeat("r", x - 1);
}
void sety(int x) {
	repeat("d", 10);
	repeat("dt", 15);
	repeat("u", x - 1);
}
void init() { // (100, 21)
	repeat("d", 21);    // (100, 0)
	repeat("0l", 100);  // (0, 0)
	repeat("0u", 23);   // (0, 23)
	repeat("d", 1);     // (0, 22)
	repeat("r", 70);    // (70, 22)
	repeat("0rst", 30); // (?, 22)
	setx(70);           // (70, 22)
	repeat("d", 1);     // (70, 21)
	repeat("0rst", 30); // (?, 21)
	setx(100);          // (100, 21)
	sety(19);           // (100, 19)
}
void copy() { // (100, 19)
	// Copy Number 1
	for (int i = 100; i >= 70; i--) { // (i, 19)
		repeat("u", 2);  // (i, 21)
		repeat("t", 1);  // (i, 20 / 19)
		repeat("0", 1);
		sety(19);        // (i, 19)
		repeat("l", 1);  // (i - 1, 19)
	} // (69, 19)
	repeat("u", 1);    // (69, 20)
	repeat("re", 31);  // (100, 20)
	// Copy Number 2
	for (int i = 100; i >= 70; i--) { // (i, 20)
		repeat("u", 2);  // (i, 22)
		repeat("t", 1);  // (i, 21 / 20)
		repeat("1", 1);
		sety(20);        // (i, 20)
		repeat("l", 1);  // (i - 1, 20)
	} // (69, 20)
}
void addition() { // (69, 20)
	for (int i = 100; i >= 70; i--) {
		// Process Line 17
		setx(i), sety(18); // (i, 18)
		repeat("dt0", 1);  // (i, 18 / 17)
		sety(17);          // (i, 17)
		repeat("e", 1);    // (i, 17)
		// Process Line 19
		repeat("uutt0", 1); // (i, 19 / 18 / 17)
		sety(18);           // (i, 18)
		repeat("dte", 1);   // (i, 18 / 17)
		sety(17);           // (i, 17)
		repeat("lrt0", 1);  // (i - 1 / i, 17);
		setx(i);            // (i, 17)
		repeat("e", 1);     // (i, 17)
		// Process Line 21
		repeat("uuutt0", 1); // (i, 20 / 18 / 17)
		sety(18);            // (i, 18)
		repeat("dte", 1);    // (i, 18 / 17)
		sety(17);            // (i, 17)
		repeat("lrt0", 1);   // (i - 1 / i, 17);
		setx(i);             // (i, 17)
		repeat("e", 1);      // (i, 17)
		// MakeAnswer
		repeat("ut0", 1);  // (i, 18 / 17)
		sety(18);          // (i, 18)
		repeat("dt1", 1);  // (i, 18 / 17)
	}
	setx(70), sety(18);
}
int main() {
	init(), copy(), addition();
	cout << ans << endl;
	return 0;
}