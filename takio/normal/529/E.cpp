#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#define LL long long
#define UN unsigned short
#define ULL unsigned long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;
map <int, int> mp;
map <int, int> :: iterator it;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, q, a;
    cin >> n >> k;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int i = 1, sum = a; i <= k; i++, sum += a) {
            if (mp.find (sum) == mp.end()) mp[sum] = i;
            else mp[sum] = min (mp[sum], i);
        }
    }
    cin >> q;
    while (q--) {
        cin >> a;
        int res = 1e9;
        for (it = mp.begin(); it != mp.end(); it++) {
            int tmp = (*it).xx;
            if (tmp > a) continue;
            if (mp.find (a - tmp) != mp.end()) res = min (res, (*it).yy + mp[a - tmp]);
        }
        if (res > k) cout << -1 << endl;
        else cout << res << endl;
    }
}