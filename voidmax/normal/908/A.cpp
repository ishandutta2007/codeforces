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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

const int MAXN = 2e5 + 1;

vector<char> bad = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};

int ans;
string s;


int main() {
	srand(time(0));
    //read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < bad.size(); ++j) {
            if (bad[j] == s[i])
                ++ans;
        }
    }
    cout << ans << endl;
}