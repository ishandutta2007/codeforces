#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp push_back
#define all(a) a.begin(), a.end()
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int p = 1e9 + 7;

int cnt = 0, n;
set <int> arr;

int main() {
	//read(FILENAME);
	cin >> n;
	for (int t = n * 2; t--;) {
		int a;
		cin >> a;
		if (arr.count(a)) {
			arr.erase(a); 
		} else {
			arr.insert(a);
		}
		cnt = max(cnt, (int)arr.size());
	}
	cout << cnt << endl;
}