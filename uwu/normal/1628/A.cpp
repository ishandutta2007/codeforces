#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
int a[MN], cnt[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        for (int i = 0; i <= N; ++i) cnt[i] = 0;
        for (int i = 1; i <= N; ++i) cin >> a[i], cnt[a[i]]++;
        vector<int> ans;
        int p = 1;
        while (p != N + 1){
            int j = 0;
            for (int i = 0; i <= N; ++i){
                if (cnt[i] == 0){
                    j = i;
                    break;
                }
            }
            ans.push_back(j);
            int idx = p;
            set<int> s;
            for (int i = p; i <= N; ++i){
                idx = i;
                cnt[a[i]]--;
                if (a[i] < j) s.insert(a[i]);
                if (s.size() == j) break;
            }
            p = idx + 1;
        }
        cout << ans.size() << '\n';
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}