#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

string names[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
map <string, int> num;
int size_month[3] = {28, 30, 31};
string a, b;

int main() {
	//read(FILENAME);
	For(i, 0, 7) num[names[i]] = i; 
	cin >> a >> b;
	For(i, 0, 3) {
		if ((num[a] + size_month[i]) % 7 == num[b]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}