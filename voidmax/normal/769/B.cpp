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

const string FileName = "input";

const int MAXN = 200;

int n, a;
vector <pair <int, int>> edge;
int R = 1;
bool used[MAXN];
vector <pair <int, int>> arr;

int main(int argc, char const *argv[]) {
    srand(time(0));
    //read(FileName);
    ios::sync_with_stdio(0);
    cin >> n;
    arr.resize(n - 1);
    cin >> a;
    for (int i = 1; i < n; ++i) {
    	int a;
    	cin >> a;
    	arr.pb({a, i});
    }
    sort(arr.rbegin(), arr.rend());
    arr.insert(arr.begin(), make_pair(a, 0));
    used[0] = true;
    for (int i = 0; i < n; ++i) {
    	if (!used[arr[i].y]) {
    		cout << -1 << endl;
    		return 0;
    	}
    	while (R < n && arr[i].x) {
    		used[arr[R].y] = true;
    		edge.pb({arr[i].y + 1, arr[R].y + 1});
    		++R;
    		--arr[i].x;
    	} 
    }
    cout << edge.size() << endl;
    for (auto i: edge) {
    	cout << i.x << ' ' << i.y << endl;
    }
}