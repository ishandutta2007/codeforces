#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 101000;

char s[N];


int c[330], n;

int main () {
//    freopen ("in", "r", stdin);
    cin >> n;
    scanf ("%s", s);
    for (int i = 0; s[i]; i++) {
        c[s[i]]++;
    }
    if (c['D'] > c['A']) cout << "Danik";
    else if (c['D'] < c['A']) cout << "Anton";
    else cout << "Friendship";
}