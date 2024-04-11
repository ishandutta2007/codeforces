#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int cnt = 0, cur = 0;
        for (int i = 0; i < N; ++i){
            int a; cin >> a;
            if (a == 0){
                if (cur) cnt++;
                cur = 0;
            }
            else cur++;
        }
        if (cur) cnt++;
        cout << min(cnt, 2) << '\n';
    }
}