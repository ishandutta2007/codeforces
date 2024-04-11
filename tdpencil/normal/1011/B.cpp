#include <bits/stdc++.h>

#define rep(i,j,n) for(int i = j; i < n; i++)
#define vi vector<int>
#define all(x) begin(x), end(x);
#define double long double
int main() {
    using namespace std;

    int T = 1;
    for(int test_case = 0; test_case < T; test_case++) {
        int M, N;
        cin >> M >> N;
        vector<int> A(N);
        vector<int> C(100);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
            ++C[A[i]-1];
        }

        for(int i = N; i >= 1; i--) {
            int ans = 0;
            for(int j : C)
                ans += j / i;
            if(ans >= M) {
                cout << i << "\n";
                return 0;
            }
        }


        cout << 0 << "\n";


    }
}