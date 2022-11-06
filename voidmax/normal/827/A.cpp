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
#define free free228
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
typedef long long base;
const int MAXN = 2e6 + 1;

int n;
int id[MAXN];
string res[MAXN];
string s;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n;
    int len = 0;
    res[0] = "";
    for (int i = 1; i <= n; ++i) {
    	cin >> res[i];
    	int k;
    	cin >> k;
    	for (int j = 0; j < k; ++j) {
    		int a;
    		cin >> a;
    		--a;
    		chkmax(len, a + res[i].size());
    		if (id[a] == 0 || res[id[a]].size() < res[i].size()) {
    			id[a] = i;
    		}
    	}
    } 
    s.resize(len, 'a');
    int res_id = 0, j = 0;
    for (int i = 0; i < len; ++i, ++j) {
    	if ((int)res[res_id].size() - j <= (int)res[id[i]].size()) {
    		j = 0;
    		res_id = id[i];
    	}
    	if (res_id != 0) {
    		s[i] = res[res_id][j];
    	} else {
    		s[i] = 'a';
    	}
    }
    cout << s << endl;

}