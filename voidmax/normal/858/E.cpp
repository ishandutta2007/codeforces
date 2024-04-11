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
#include <random>  
#include <ctime>
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1e6 + 1;

int n, cnt;
set <string> cool, que;
vector <pair <string, bool>> arr;

queue <int> A[3];
set <int> B[2];
string bin;

string res[MAXN];

vector <pair <string, string>> ans;

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FILENAME);
	srand(time(0));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s = "";
		int k = i;
		while (k) {
			s += char('0' + k % 10);
			k /= 10;
		}
		reverse(s.begin(), s.end());
		res[i] = s;
		cool.insert(s);
	}
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].x >> arr[i].y;
		if (arr[i].y) ++cnt;
	}
	for (int i = 1; i <= n; ++i) {
		if (i <= cnt) {
			B[0].insert(i);
		} else {
			B[1].insert(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (cool.count(arr[i].x)) {
			int j = atoi(arr[i].x.c_str());
			if ((j <= cnt && arr[i].y) || (j > cnt && !arr[i].y)) {
				B[!arr[i].y].erase(j);
			} else {
				//cout << j << ' ' << arr[i].y << ' ' << cnt << endl;
				B[arr[i].y].erase(j);
				A[arr[i].y].push(i);
			}
		} else {
			A[2].push(i);
		}
	}
	while (true) {
		bin = "";
		for (int i = 0; i < 6; ++i) {
			bin += char('a' + (rand() % 26));
		}
		bool OK = true;
		for (int i = 0; i < n; ++i) {
			if (arr[i].x == bin) {
				OK = false;
				break;
			}
		}
		if (OK) break;
	}
	while (A[0].size() || A[1].size() || A[2].size()) {
		if (B[0].size() && A[1].size()) {
			int i = A[1].front();
			A[1].pop();
			int j = *B[0].begin();
			B[0].erase(j);
			ans.pb({arr[i].x, res[j]});
			B[1].insert(atoi(arr[i].x.c_str()));
			//arr[i].x = itoa(j);
		} else if (B[1].size() && A[0].size()) {
			int i = A[0].front();
			A[0].pop();
			int j = *B[1].begin();
			B[1].erase(j);
			ans.pb({arr[i].x, res[j]});
			B[0].insert(atoi(arr[i].x.c_str()));
			//arr[i].x = itoa(j);
		} else if (A[2].size()) {
			int i = A[2].front();
			A[2].pop();
			if (arr[i].y) {
				int j = *B[0].begin();
				B[0].erase(j);
				ans.pb({arr[i].x, res[j]});
				//arr[i].x = itoa(j);
			} else {
				int j = *B[1].begin();
				B[1].erase(j);
				ans.pb({arr[i].x, res[j]});
				//arr[i].x = itoa(j);
			}
		} else {
			int a = A[0].front();
			A[0].pop();
			A[2].push(a);
			int j = atoi(arr[a].x.c_str());
			B[0].insert(j);
			ans.pb({arr[a].x, bin});
			arr[a].x = bin;
			//swap(arr[a].x, arr[b].x);
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << "move " << i.x << ' ' << i.y << '\n';
	}
}