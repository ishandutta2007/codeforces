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
#define x first
#define y second

using namespace std;

int k, n;
int sum;
int arr[100001];
bool used[100001][6];


int f(int X) {
    if (k % 2 == 0) {
        if (X == 1) return 1;
        if (X == 2) return 2;
        return (X + 1) % 2;
    } else {
        if (X == 1) return 1;
        if (X == 2) return 0;
        if (X == 3) return 1;
        if (X == 4) return 2;
        if (X % 2 == 1) return 0;
        int ans = f(X >> 1);
        if (ans == 1) return 2;
        return 1;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    For(i, 0, n) {
        int a;
        cin >> a;
        sum ^= f(a);
    }
    if (sum != 0) cout << "Kevin";
    if (sum == 0) cout << "Nicky";
}