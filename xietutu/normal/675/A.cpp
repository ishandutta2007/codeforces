#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c;
int main() {
	cin >> a >> b >> c;
	if (c == 0 && a == b) cout << "YES" << endl;
	else if (c > 0 && b >= a && (b - a) % c == 0) cout << "YES" << endl;
	else if (c < 0 && b <= a && (b - a) % c == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}