#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100010, mod = 1e9 + 7;

map <pii, int> mp1;
map <pii, int> :: iterator it1;
map <int, int> mp2, mp3;
map <int, int> :: iterator it2;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x, &y);
        mp1[pii (x, y)]++;
        mp2[x]++;
        mp3[y]++;
    }
    LL res = 0;
    for (it1 = mp1.begin(); it1 != mp1.end(); it1++) {
        res -= 1LL * (*it1).yy * ((*it1).yy - 1) / 2;
    }
    for (it2 = mp2.begin(); it2 != mp2.end(); it2++) {
        res += 1LL * (*it2).yy * ((*it2).yy - 1) / 2;
    }
    for (it2 = mp3.begin(); it2 != mp3.end(); it2++) {
        res += 1LL * (*it2).yy * ((*it2).yy - 1) / 2;
    }
    cout << res << endl;
}