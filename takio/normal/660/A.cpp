#include <bits/stdc++.h>
//#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <set>
//#include <ctime>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

const int N = 100100;
int main () {
    int n, a, b;
    cin >> n;
    vector <int> r;
    scanf ("%d", &a);
    r.push_back (a);
    for (int i = 2; i <= n; i++) {
        scanf ("%d", &b);
        if (__gcd (a, b) != 1) r.push_back (1);
        r.push_back (b);
        a = b;
    }
    cout <<r.size() -n << endl;
    for (int i = 0; i< r.size(); i++) printf ("%d ", r[i]);
}