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
#define point pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long base;

base n, m, k;
base a[200001]; base ans[200001];
base cnt[2000001];
vector <pair <point, int>> arr;
const int p = 330;

bool cmp(pair <point, int> a, pair <point, int> b) {
    if (a.x.x / p == b.x.x / p) {
        return a.x.y < b.x.y;
    }
    return a.x.x / p < b.x.x / p;
}


base Now = 0;
void change(int a, int s) {
    if (k != 0) {
        Now -= cnt[a] * cnt[k ^ a];
        cnt[a] += s;
        Now += cnt[a] * cnt[k ^ a];
    } else {
        Now -= cnt[a] * (cnt[a] - 1) / 2;
        cnt[a] += s;
        Now += cnt[a] * (cnt[a] - 1) / 2;
    }
}

int main() {
    cin >> n >> m >> k;
    For(i, 1, n + 1) {
        cin >> a[i];
        a[i] = a[i - 1] ^ a[i];
    }
    For(i, 0, m) {
        int L, R; cin >> L >> R;
        arr.push_back({{L, R}, i});
    }
    sort(arr.begin(), arr.end(), cmp);
    int L = 1, R = 0;
    for(auto i: arr) {
        while (i.x.y > R) {
            ++R; change(a[R], 1);
        }
        while (i.x.x < L) {
            --L; change(a[L], 1);
        }
        while (i.x.y < R) {
            change(a[R], -1); --R;
        }
        while (i.x.x > L) {
            change(a[L], -1); ++L;
        }
        Now += (base)cnt[a[i.x.x - 1] ^ k];
        ans[i.y] = Now;
        Now -= (base)cnt[a[i.x.x - 1] ^ k];
    }
    For(i, 0, m) cout << ans[i] << endl;
}