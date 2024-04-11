#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;


    while(T--) {
        int N;
        cin >> N;
        vi A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<bool> F(N+2);
        vector<bool> suffix(N);
        vector<bool> prefix(N);
        int mex = 1;
        for(int i = 0; i < N; i++) {
            F[A[i]] = true;
            while(F[mex]) mex++;
            if(mex == i + 2)
                prefix[i] = true;
        }

        mex = 1;
        fill(all(F), false);
        for(int i = N - 1; i >= 0; i--) {
            F[A[i]] = true;
            while(F[mex]) mex++;
            if(mex == N - i + 1)
                suffix[i] = true;
        }
        vector<pair<int, int>> operations;
        for(int i = 0; i < N - 1; i++) {
            if(prefix[i] && suffix[i + 1]) {
                operations.emplace_back(i + 1, N - i - 1); 
            }
        }
        cout << operations.size() << "\n";
        for(auto &response : operations) {
            cout << response.first << " " << response.second << "\n";
        }
        
        
    }
}