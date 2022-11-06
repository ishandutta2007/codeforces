#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <vector>
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

string a;

int arr[11][11];


main() {
    //freopen("input.txt", "r", stdin);
    //freopen("", "r", stdin);freopen("", "w", stdout);
    cin >> a;
    int ans = 0;
    reverse(a.begin(), a.end());
    For(i, 0, a.size()) {
        For(q, 0, a[i] - '0') {
            ++arr[q][i];
        }
        ans = max(ans, a[i] - '0');
    }
    cout << ans << endl;
    For(i, 0, ans) {
        bool OK = false;
        for(int q = 9; q > -1; --q) {
            if (arr[i][q]) {
                OK = true;
                cout << arr[i][q];
            }
            else {
                if (OK) {
                    cout << arr[i][q];
                }
            }
        }
        cout << ' ';
    }
}