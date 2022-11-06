//#include "grader.h"
#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int n, a;
int R[200001];
vector <pair <int, int>> arr;
bool used[200001];

bool check(int M) {
    For(i, 0, n) used[i] = false;
    set <pair <int, int>> que;
    int cnt = 0;
    For(i, 0, arr.size()) {
        while (que.size() && (*que.begin()).x <= arr[i].x) {
            used[(*que.begin()).y] = true;
            que.erase(que.begin());
            ++cnt;
        }
        if (cnt >= a) return true;
        if (que.size() == M) {
            auto Id = que.end(); --Id;
            if ((*Id).x > R[arr[i].y]) {
                que.erase(Id);
                que.insert({R[arr[i].y], arr[i].y});
            }
        } else {
            que.insert({R[arr[i].y], arr[i].y});
        }
    }
    while (que.size()) {
        used[(*que.begin()).y] = true;
        que.erase(que.begin());
        ++cnt;
    }
    return (cnt >= a);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a;
    For(i, 0, n) {
        int L, R1; cin >> L >> R1;
        R1 += L;
        arr.pb({L, i});
        R[i] = R1;
    }
    sort(arr.begin(), arr.end());
    int L = 0, R = a;
    while (R - L > 1) {
        int M = (R + L) >> 1;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    check(R);
    cout << R << endl;
    For(i, 0, n) {
        if (used[i]) {
            --a;
            cout << i + 1 << ' ';
        }
        if (!a) break;
    }
}