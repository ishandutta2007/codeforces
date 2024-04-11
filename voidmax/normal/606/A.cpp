/*
 - - - - - - - -
 
 ***********
 ***********
 ***
 ***
 ***********
 ***********
 ***
 ***
 ***********
 ***********
 
 - - - - - - - -
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

int a[3], b[3];

int main() {
    ios::sync_with_stdio(false);
    For(i, 0, 3) cin >> a[i];
    For(i, 0, 3) cin >> b[i];
    while (a[0] - 2 >= b[0] || a[1] - 2 >= b[1] || a[2] - 2 >= b[2]) {
        if (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]) break;
        For(i, 0, 3) {
            if (a[i] - 2 >= b[i]) {
                For(j, 0, 3) {
                    if (a[j] < b[j]) {
                        a[i] -= 2;
                        ++a[j];
                        break;
                    }
                }
            }
        }
    }
    if (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}