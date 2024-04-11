#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define pii pair <int, LL>
#define piii pair <pii, int>
using namespace std;

const int N = 111111;
const LL INF = 1LL << 60;

int mp[20][20];

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || j == 1) mp[i][j] = 1;
            else mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
        }
    }
    cout << mp[n][n];
}