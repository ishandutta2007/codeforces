#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<int> a(M);
        for (int i = 0; i < M; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> v;
        for (int i = 1; i < M; ++i){
            v.push_back(a[i] - a[i - 1] - 1);
        }
        v.push_back(a[0] + N - a.back() - 1);
        sort(v.begin(), v.end(), greater<int>());
        int pen = 0, ans = 0;
        for (int x : v){
            x -= pen;
            if (x <= 0) break;
            if (x == 1){
                ans++;
                break;
            }
            ans += x - 1;
            pen += 4;
        }
        cout << N - ans << '\n';
    }
}