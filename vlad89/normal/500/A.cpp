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
#endif
    int n, t;
    cin >> n >> t;
    vector<bool> a(n);
    a[0] = true;
    REP(i, n-1) {
      int x;
      cin >> x;
      if (a[i]) 
	a[i+x] = true;
    }
    if (a[t-1]) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}