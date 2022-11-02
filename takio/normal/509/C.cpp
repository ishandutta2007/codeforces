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

const int N = 400;
const LL INF = 1LL << 60;

int s[N];
int a, pa;

void solve () {
    int t = pa;
    for (int i = 0; i < N; i++) {
//        cout << "out " << i << ' ' << t << endl;
        if (s[i] != 9 && t + 1 <= a && t - s[i] + 9 * (i + 1) >= a) {
            a -= t - s[i];
//            cout << t << ' ' << i << ' ' << a << endl;
//            cout << "a " << a << endl;
            if (s[i] + 9 * i + 1 <= a) {
//                cout << "NO1" << endl;
                for (int j = 0; j < i; j++) s[j] = 9;
                s[i] = a - 9 * i;
            } else {
                s[i]++;
                a -= s[i];
                int now = 0;
                while (a >= 9) {
                    s[now++] = 9;
                    a -= 9;
                }
                s[now++] = a;
                for (; now < i; now++)
                    s[now] = 0;
            }
            return;
        }
        t -= s[i];
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        int ta = a;
        solve ();
        int t = 390;
        while (!s[t]) t--;
        for (; t != -1; t--) {
            cout << s[t];
        }
        cout << endl;
        pa = ta;
    }
}