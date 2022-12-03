#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int k[3], t[3];
deque<long long> go[3];
int a[123456];
int n;

int main() {
    #ifdef LocalHost
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf ("%d%d%d", &k[0], &k[1], &k[2]);
    scanf ("%d%d%d", &t[0], &t[1], &t[2]);
    scanf ("%d", &n);
    long long ans = 0;
    REP (i, n) {
        scanf ("%d", a+i);
        long long T = a[i];
        REP (j, 3) {
            if (sz(go[j]) == k[j]) {
                T = max (T, go[j].front());
                go[j].pop_front();                
            }
            T += t[j];
            go[j].push_back(T);
        }
        ans = max(ans, T-a[i]);
    }
    cout << ans << endl;
	return 0;
}