#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1111111;
const int MAGIC = 7;

typedef unsigned long long Hash;

int n, m, a[N], b[N];
Hash power[N], hashes[N];

int main() {
    scanf("%d%d", &n, &m);
    power[0] = 1;
    for (int i = 1; i < n; ++ i) {
        power[i] = power[i - 1] * MAGIC;
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", a + i, b + i);
        a[i] --;
        b[i] --;
        hashes[a[i]] += power[b[i]];
        hashes[b[i]] += power[a[i]];
    }
    vector <Hash> vs;
    for (int i = 0; i < n; ++ i) {
        vs.push_back(hashes[i]);
    }
    sort(vs.begin(), vs.end());
    long long result = 0;
    for (int i = 0; i < n; ++ i) {
        int j = i;
        while (j + 1 < n && vs[i] == vs[j + 1]) {
            j ++;
        }
        long long size = j - i + 1;
        result += size * (size - 1);
        i = j;
    }
    for (int i = 0; i < m; ++ i) {
        result += (hashes[a[i]] - power[b[i]] == hashes[b[i]] - power[a[i]]) * 2;
    }
    cout << result / 2 << endl;
    return 0;
}