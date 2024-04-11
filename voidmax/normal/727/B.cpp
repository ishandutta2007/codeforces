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
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

typedef long long base;

const string FILENAME = "input";

int head = 0;
string s;

long long sum = 0;

int count_after(int last) {
	if (last == -1) return 0;
	++last;
	int cnt = 0;
	while ('0' <= s[last] && s[last] <= '9') {
		++cnt;
		++last;
	}
	return cnt;
}

int read_double() {
	int res = 0;
	int last = -1;
	while (('0' <= s[head] && s[head] <= '9') || (s[head] == '.')) {
		if (s[head] == '.') {
			last = head++;
			continue;
		}
		res *= 10;
		res += s[head++] - '0';
	}
	if (count_after(last) != 2) {
		res *= 100;
	}
	return res;
} 


void print_num(long long sum) {
 	long long L = sum / 100, R = sum % 100;
 	string res1 = "", res2 = "";
 	while (L != 0) {
 		res1 += '0' + L % 10;
 		L /= 10;
 	}
 	reverse(res1.begin(), res1.end());
 	res2 += R / 10 + '0';
 	res2 += R % 10 + '0';
 	if (res1.size() == 0)
 		res1 = "0";
 	For(i, 0, res1.size()) {
 		if ((res1.size() - i) % 3 == 0 && i != 0) {
 			cout << '.';
 		}
 		cout << res1[i];
 	}
 	if (R != 0) {
 		cout << '.' << res2;
 	}
}

int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	cin >> s;	
	s += '#';
	while (s[head] != '#') {
		while (!('0' <= s[head] && s[head] <= '9')) {
			++head;
		}
		int c = read_double();
		sum += c;
	}
	print_num(sum);
}