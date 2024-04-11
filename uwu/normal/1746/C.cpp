#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N), idx(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return a[i] > a[j];
        });
        for (int i = 0; i < N; ++i){
            cout << idx[i]+1 << " ";
        }
        cout << '\n';
    }
}