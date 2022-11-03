#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)

int main() {
    int n, t;cin >> n >> t;
    vector<int> s(n), d(n); FOR(i, 0, n) cin >> s[i] >> d[i];

    int abc[110];

    FOR(i, 0, n) {
        int k = 0;
        while(t > s[i] + k * d[i]) {
            k++;
        }
        abc[i] = -t+s[i]+k*d[i];
    }

    int l = 1;
    int mini=abc[0];
    FOR(i, 0, n) {
        if(mini >= abc[i]) {
            l = i+1;
            mini =abc[i];
        }
    }

    printf("%d\n", l);
}