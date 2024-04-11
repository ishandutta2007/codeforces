#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<int> a(N);
        bool one = 0;
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            if (a[i] == 1) one = 1;
        }
        cout << (one ? "YES" : "NO") << '\n';
    }
}