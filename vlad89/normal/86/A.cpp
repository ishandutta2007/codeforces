#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset((a),(b),sizeof(a))

#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

long long num(long long x) {
    long long g = 0;
    while (x) {
        g = g*10 + 9;
        x /= 10;
    }
    return g;
}

long long getans(long long x) {
    return num(x)*x - x*x;
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int l, r;
    cin >> l >> r;
    
    long long f = num(l);
    if (f < r)
        l = num(r)/10+1;
    while (r - l > 100) {
        long long mid = (l+r) / 2;
        long long t1 = (l+mid) / 2;
        long long t2 = (r+mid) / 2;
        
        if (getans(t1) < getans(t2))
            l = t1;
        else
            r = t2;
    }
    long long ans = getans(l);
    FOR (i, l, r+1) {
        ans = max(ans, getans(i));
    }
    cout << ans << endl;
	return 0;
}