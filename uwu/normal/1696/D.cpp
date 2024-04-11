#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }

        vector<int> mx(N), mn(N);
        mx[N - 1] = a[N - 1];
        mn[N - 1] = a[N - 1];
        for (int i = N - 2; i >= 0; --i){
            mx[i] = max(a[i], mx[i + 1]);
            mn[i] = min(a[i], mn[i + 1]);
        }

        int i = 0, ans = 0;
        while (i != N - 1){
            if (a[i + 1] > a[i]){
                int j = i + 1;
                for (int k = i + 1; k < N; ++k){
                    if (a[k] < a[i]) break;
                    if (a[k] > a[j]) j = k;
                    if (a[k] == mx[k]) break;
                }
                i = j;
            }
            else{
                int j = i + 1;
                for (int k = i + 1; k < N; ++k){
                    if (a[k] > a[i]) break;
                    if (a[k] < a[j]) j = k;
                    if (a[k] == mn[k]) break;
                }
                i = j;
            }
            ans++;
        }
        cout << ans << '\n';
    }
}