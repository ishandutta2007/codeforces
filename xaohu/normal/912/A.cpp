#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

ll A, B, x, y, z;

int main() {
	cin >> A >> B >> x >> y >> z;
	A -= 2 * x + y;
	B -= y + 3 * z;
	A = min(A, 0ll);
	B = min(B, 0ll);
	cout << -(A + B) << endl;
	return 0;
}