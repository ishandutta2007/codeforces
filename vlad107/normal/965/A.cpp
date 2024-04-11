#include <iostream>

using namespace std;

int main() {
	long long k, n, s, p;
	cin >> k >> n >> s >> p;
	long long cntS = (n + s - 1) / s;
	long long cntSAll = cntS * k;
	long long cntP = (cntSAll + p - 1) / p;
	cout << cntP << endl;
	return 0;
}