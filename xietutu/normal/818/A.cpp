#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long LL;
LL n, k;
int main() {
	cin >> n >> k;
	LL y = n / (2 * (k + 1));
	LL x = k * y;
	LL left = n - x - y;
	cout << y << " " << x << " " << left << endl;
}