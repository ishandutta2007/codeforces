#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        int ans = N;
        for (int i = 1; i < 2*N; ++i){
            if (s[i] == '(' && s[i-1] == ')') ans--;
        }
        cout << ans << '\n';
    }
}