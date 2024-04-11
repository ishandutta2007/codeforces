#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 200100;

char s[N], t[N];
int vis[N];
int cnt[500];

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s%s", s, t);
    for (int i = 0; t[i]; i++) {
        cnt[t[i]]++;
    }
    int res1 = 0, res2 = 0;
    for (int i = 0; s[i]; i++) {
        if (cnt[s[i]]) cnt[s[i]]--, res1++, vis[i] = 1;
    }
    for (int i = 0; s[i]; i++) if (!vis[i]) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] -= 'A', s[i] += 'a';
        else s[i] -= 'a', s[i] += 'A';
        if (cnt[s[i]]) cnt[s[i]]--, res2++;
    }
    cout << res1 << ' ' << res2 << endl;
}