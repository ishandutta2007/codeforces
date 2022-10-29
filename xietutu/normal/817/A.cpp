#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
inline int Abs(int x) { return x > 0 ? x : -x;}
int main() {
	int x1, y1, x2, y2, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	if ((x2 - x1) % x == 0 && (y2 - y1) % y == 0 && (Abs(x2 - x1) / x) % 2 == (Abs(y2 - y1) / y) % 2)  puts("YES");
	else puts("NO");
}