#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#define For(i, a, b)  for(int i = a; i < b; ++i)
#define read(s1, s2); freopen(s1, "r", stdin); freopen(s2, "w", stdout);
#define int long long

using namespace std;

int n;
int arr[5001];
int sum[5001];
int counter = 0;

int dfs(int i) {
    if (i >= (1 << n)) {
        return 0;
    }
    dfs(i << 1);
    dfs((i << 1) + 1);
    int s1 = arr[i << 1] + sum[i << 1];
    int s2 = arr[(i << 1) + 1] + sum[(i << 1) + 1];
    counter += max(s1 - s2, s2 - s1);
    sum[i] = max(s1, s2);
}

main() {
    cin >> n;
    For(i, 0, (1 << n + 1) - 2) {
        cin >> arr[i + 2];
    }
    dfs(1);
    cout << counter;
}