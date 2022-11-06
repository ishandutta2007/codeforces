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

int n, k;
int Ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    For(i, 0, n) {
        int a, b;
        cin >> a >> b;
        Ans = max(Ans, b - (k - a));
    }
    cout << Ans + k << endl;
}