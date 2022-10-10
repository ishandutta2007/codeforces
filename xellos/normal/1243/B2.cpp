#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        string S[2];
        cin >> N >> S[0] >> S[1];
        vector< pair<int, int> > ans;
        for(int i = 0; i < N; i++) if(S[0][i] != S[1][i]) {
            for(int j = i+1; j < N; j++) if(S[0][j] == S[0][i] && S[0][j] != S[1][j]) {
                ans.push_back({j, i});
                swap(S[0][j], S[1][i]);
                break;
            }
            if(S[0][i] != S[1][i]) for(int j = i+1; j < N; j++) if(S[1][j] == S[0][i] && S[0][j] != S[1][j]) {
                ans.push_back({j, j});
                swap(S[0][j], S[1][j]);
                ans.push_back({j, i});
                swap(S[0][j], S[1][i]);
                break;
            }
        }
        if(S[0] != S[1]) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n" << ans.size() << "\n";
        for(auto p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
    }
}