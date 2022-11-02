#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

char s[1010];
int n;

int main () {
    int mx = 0, c[30];
    cin >> s >> n;
    for (int i = 1; i <= 26; i++){
        cin >> c[i];
        mx = max (mx, c[i]);
    }
    int l = strlen (s);
    long long res = 0;
    for (int i = 0; i < l; i++)
        res += (i + 1) * c[s[i] - 'a' + 1];
    for (int i = 1; i <= n; i++)
        res += mx * (i + l);
    cout << res;
}