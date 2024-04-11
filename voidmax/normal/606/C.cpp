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
#include <queue>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

int n;
int arr[100001][2];
int ans[100001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {cin >> arr[i][0]; arr[arr[i][0] - 1][1] = i;}
    ans[0] = 1;
    int q = 1;
    For(i, 1, n) {
        if (arr[i][1] > arr[i - 1][1]) {
            ans[i] = ans[i - 1] + 1;
        } else {
            ans[i] = 1;
        }
        q = max(q, ans[i]);
    }
    cout << n - q << endl;
}