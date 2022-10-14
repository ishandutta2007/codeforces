#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7, M = (1e9+7), MAXN = 1 * 2e5;
int A[MAXN], C[MAXN];


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    int mx = 0, mn = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] > A[mx]) {
            mx = i;
        } else if(A[i] < A[mn]) {
            mn = i;
        }
    }
    mx++;
    mn++;
    if(mx < mn) swap(mx, mn);
    
    cout << min(min(max(mn, mx), max(N - mx + 1, N - mn + 1)), mn + (N - mx + 1)) << "\n";;

    

    // 3 choices
    //
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;

    while(T--) {
        solve();
    }
}