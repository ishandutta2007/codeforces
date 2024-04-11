#include <bits/stdc++.h>

#define rep(i,j,n) for(int i = j; i < n; i++)
#define vi vector<int>
#define all(x) begin(x), end(x);
#define double long double
int main() {
    using namespace std;

    int T = 1;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        int N; cin >> N;
        vector<int> X(N), Y(N);
        for(int i = 0; i < N; i++)
            cin >> X[i] >> Y[i];

        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        if(N % 2 == 1) {
            cout << 1 << '\n';
        } else {
            cout << 1LL * (X[N/2] - X[N / 2 - 1] + 1) * (Y[N/2] - Y[N / 2 - 1] + 1) << '\n';
        }
    }


}