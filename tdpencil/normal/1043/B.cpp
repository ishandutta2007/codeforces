#include <bits/stdc++.h>

#define rep(i,j,n) for(int i = j; i < n; i++)
#define vi vector<int>
#define all(x) begin(x), end(x);
#define double long double
int main() {
    using namespace std;

    int T = 1;
    // cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        int N; cin >> N;
        vector<int> A(N + 1); for(int i = 1; i <= N; i++) cin >> A[i];

        vector<int> B(N);
        for(int i = 0; i < N; i++)
            B[i] = A[i + 1] - A[i];
        vector<int> ans;
        for(int i = 0; i < N; i++) {
            vector<int> R;
            for(int j = 0; j <= i; j++)
                R.push_back(B[j]);
            int p = 0; 
            bool works = true;
            for(int j = 0; j < N; j++)
                works &= B[j] == R[(p++)%R.size()];
            if(works)
                ans.emplace_back(i + 1);
        }

        cout << ans.size() << '\n';
        for(int a : ans)
            cout << a << " ";
        cout << '\n';
    }
}