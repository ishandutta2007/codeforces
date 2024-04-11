#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;

    for(int tt = 0; tt < T; tt++){
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N); for(auto &a: A) cin >> a;
        sort(A.begin(), A.end());
        int mn = INT_MAX-1;
        for(int i=0; i < N; i++) {
            if(A[i] > Q) {
                mn = min(mn, 2);
            } else {
                mn = min(mn, ( (Q + A[i] - 1) / A[i] ));
            }
        }
        cout << mn << '\n';

    }
}