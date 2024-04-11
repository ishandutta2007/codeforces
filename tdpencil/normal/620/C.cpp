#include <bits/stdc++.h>

int main() {
    using namespace std;
    int T = 1;
//    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> A(N); for(auto &a: A) {
            cin >> a;
        }

        vector<array<int, 2>> partitions;
        
        set<int> st;

        for (int i = 0; i < N; i++) {
            if(st.count(A[i])) {
                partitions.push_back({i - (int)st.size(), i});
                st.clear();
            } else {
                st.insert(A[i]);
            }
        }
        if(partitions.empty()) {
            cout << -1 << "\n";
            return 0;
        }
        cout << partitions.size() << "\n";
        for(int i = 0; i + 1 < (int)partitions.size(); i++) {
            cout << partitions[i][0] + 1 << " " << partitions[i][1] + 1 << "\n";
        }
        int K = partitions.size();
        cout << partitions[K - 1][0] + 1 << " " << N << "\n";
    }

    return 0;
}