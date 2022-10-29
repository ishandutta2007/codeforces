#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
int N = 100;
bool check(int a) {
	for (int i = a * a; i <= N; i *= a) {
		cout << i << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if (str == "yes") return false;
	}
	for (int i = a + 1; i * a <= N; ++i) {
		bool flag = true;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0) flag = false;
		if (flag) {
			cout << i << endl;
			fflush(stdout);
			string str;
			cin >> str;
			if (str == "yes") return false;
		}
	}
	return true;
}
int main() {
	for (int i = 2; i <= 50; ++i) {
		bool flag = true;
 		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0) flag = false;
		if (flag) {
			cout << i << endl;
			fflush(stdout);
			string str;
			cin >> str;
			if (str == "yes") {
				bool ret = check(i);
				if (ret) cout << "prime";
				else cout << "composite";
				cout << endl;
				fflush(stdout);
				return 0;
			}
		}
	}
	cout << "prime" << endl;
	fflush(stdout);
	return 0;
}