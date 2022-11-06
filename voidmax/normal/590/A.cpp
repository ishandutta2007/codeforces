#include <iostream>
#include <algorithm>
#include <set>
#include <time.h>
#include <queue>
#include <random>
#include <vector>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a; i > b; --i)
#define mp make_pair
#define x first
#define y second
#define elif else if
#define point pair <double, double>
#define inf 1e9
#define eps 1e-6
#define ll long long
#define rand1() (rand() - RandMax >> 1)

using namespace std;

int n;
int arr[600000];
int ans;

void JustDoIt(int L, int R) {
    int cnt = 0;
    bool Start = 0;
    while (L <= R) {
        ++cnt;
        arr[L] ^= Start;
        if (R != L) arr[R] ^= Start;
        Start ^= 1;
        ++L; --R;
    }
    ans = max(ans, cnt - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 1, n + 1) cin >> arr[i];
    arr[0] = arr[1]; arr[n + 1] = arr[n];
    int L = 1, R = 1;
    For(i, 1, n + 2) {
        if (arr[i] == arr[i - 1]) {
            if (R - L > 1) {
                JustDoIt(L, R);
            }
            L = R = i;
        } else {
            ++R;
        }
    }
    cout << ans << endl;
    For(i, 1, n + 1) {
        cout << arr[i] << ' ';
    }
}