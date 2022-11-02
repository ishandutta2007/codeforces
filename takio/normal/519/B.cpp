#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;
int a[N], b[N], c[N];
map <int, int> mp, mp2;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        mp[a[i]]++;
    }
    for (int i = 1; i <= n - 1; i++) {
        scanf ("%d", &b[i]);
        mp[b[i]]--;
        mp2[b[i]]++;
    }
    for (int i = 1; i <= n - 2; i++) {
        scanf ("%d", &c[i]);
        mp2[c[i]]--;
    }
    for (int i = 1; i <= n; i++) if (mp[a[i]]) { cout << a[i] << endl; break; }
    for (int i = 1; i < n; i++) if (mp2[b[i]]) { cout << b[i] << endl; break; }
}