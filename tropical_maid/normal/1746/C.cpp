#include <bits/stdc++.h>

using namespace std;

int A[100005], P[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> S;
        for (int i = 1; i <= n; ++i) {
            S.insert(i);
            P[i] = 1;
            cin >> A[i];
        }
        for (int i = 2; i <= n; ++i) {
            int d = *S.lower_bound(A[i - 1] - A[i]);
            S.erase(d);
            P[d] = i;
        }
        for (int i = 1; i <= n; ++i) printf("%d%c", P[i], " \n"[i == n]);
    }
    return 0;
}