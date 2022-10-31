#include <bits/stdc++.h>
using namespace std;

vector<int> queries = { 4, 9, 25, 49, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
string res;

int main() {
	int bad = 0;
	for (int i: queries) {
		cout << i << endl;
		cin >> res;
		bad+=(res=="yes");
	}
	cout << (bad>1 ? "composite" : "prime") << endl;

	return 0;
}