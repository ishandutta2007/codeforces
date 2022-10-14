#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--) {
        int N, U, V;
        cin >> N >> U >> V;

        vector<int64_t> A(N); for(auto &a: A) cin >> a;
        set<int64_t> s;
        for(auto &e: A) s.insert(e);
        if(s.size() == 1) {
            cout << min(U, V) + V << "\n";
            continue;
        }
        bool works = false;
        for(int i = 0; i < N-1; i++) {
            if(abs(A[i+1] - A[i])  > 1) {
                cout << 0 << "\n";
                works = true;
                break;
            }
        }
        if(works) continue;


        cout << min(U, V) << "\n";
    }
}