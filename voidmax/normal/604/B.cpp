/*
 - - - - - - - -
 
 *********
 ***********
 ***     ***
 ***    ***
 *********
 *********
 ***    ****
 ***     ***
 **********
 *********
 
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
#define x first
#define y second

using namespace std;

int n, k;
int arr[1000001];
int L = 0, R = 2000001;

bool check(int M) {
    int L = 0;
    int cnt = 0;
    Out(i, n, 0) {
        if (i < L) break;
        ++cnt;
        if (arr[i] + arr[L] <= M) {
            ++L;
        } else if (arr[i] > M) {
            return false;
        }
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    For(i, 0, n) cin >> arr[i];
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << endl;
}