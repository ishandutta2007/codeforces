#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n, m;
    double kk;
    cin >> n >> m >> kk;
    int k = (int) (kk * 100 + 1e-9);
    string s;
    int g;
    map<string, int> res;
    REP (i, n) {
	cin >> s >> g;
	g *= k;
	g /= 100;
	if (g >= 100)
	    res[s] = g;
    }
    REP (i, m) {
	cin >> s;
	if (!res.count(s))
	    res[s] = 0;
    }
    cout << sz(res) << endl;
    for (map<string, int>::iterator it = res.begin(); it != res.end(); ++it)
	cout << it->X << ' ' << it->Y << endl;
    return 0;
}