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
        vector<array<int, 2>> A(N);
        for(int i = 0; i < N; i++)
            cin >> A[i][0] >> A[i][1];

        sort(A.begin(), A.end());
        bool works = true;
        for(int i = 1; i < N; i++)
            works &= A[i][0] >= A[i - 1][0] && A[i][1] >= A[i - 1][1];
        if(!works) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int l = 0, r = 0;
        int cur = 0;
        while(cur < N) {
            while(l != A[cur][0]) {
                cout << "R";
                l++;
            }
            while(r != A[cur][1]) {
                cout << "U";
                ++r;
            }
            ++cur;
        }
        cout << "\n";
    }
}