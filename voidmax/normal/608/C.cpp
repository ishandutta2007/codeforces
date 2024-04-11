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

int n;
vector <point> arr;
int ans[100001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    For(i, 0, n) {
        int L = -1, R = i;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (arr[i].x - arr[i].y <= arr[M].x) {
                R = M;
            } else {
                L = M;
            }
        }
        if (L == -1) ans[i] = i;
        else ans[i] = i - L - 1 + ans[L];
    }
    int cnt = 1e9;
    For(i, 0, n) cnt = min(cnt, ans[i] + n - i - 1);
    cout << cnt << endl;
}