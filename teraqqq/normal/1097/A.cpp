#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

const int N = 20;
const int A = 360;

char a[3], b[3];
bool can = false;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> a;
	for(int i = 0; i < 5; ++i) {
		cin >> b;
		if(a[0] == b[0] || a[1] == b[1])
			can = true;
	}

	cout << (can ? "YES" : "NO");
}