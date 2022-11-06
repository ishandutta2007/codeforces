#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second

using namespace std;

typedef long long base;

int ans[0];
point a[3];
set <base> arr[2];

int main() {
    For(i, 0, 3) {
        cin >> a[i].x >> a[i].y;
        arr[0].insert(a[i].x);
        arr[1].insert(a[i].y);
    }
    if (arr[0].size() == 1 || arr[1].size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (arr[0].size() == 3 && arr[1].size() == 3) {
        cout << 3 << endl;
        return 0;
    }
    if (arr[0].size() == 2 && arr[1].size() == 2) {
        cout << 2 << endl;
        return 0;
    }
    For(i, 0, 3) {
        For(j, 0, 3) {
            For(k, 0, 3){
                if (a[i].x == a[j].x && a[i].y < a[j].y && a[i].y < a[k].y && a[k].y < a[j].y) {
                    cout << 3 << endl;
                    return 0;
                }
                if (a[i].y == a[j].y && a[i].x < a[j].x && a[i].x < a[k].x && a[k].x < a[j].x) {
                    cout << 3 << endl;
                    return 0;
                }
            }
        }
    }
    cout << 2 << endl;
}