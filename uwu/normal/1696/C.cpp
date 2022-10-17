#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        int M; cin >> M;
        vector<int> b(M);
        for (int i = 0; i < M; ++i){
            cin >> b[i];
        }

        using pii = pair<int, int>;
        auto decomp = [&](vector<int> v){
            vector<pii> ret;
            for (int i = 0; i < v.size(); ++i){
                int cnt = 0, add = 1;
                while (v[i] % K == 0){
                    cnt++;
                    v[i] /= K;
                    add *= K;
                }
                ret.push_back({v[i], add});
            }
            return ret;
        };

        vector<pii> ad = decomp(a);
        vector<pii> bd = decomp(b);
        int i = 0, j = 0;
        while (i < ad.size() && j < bd.size()){
            if (ad[i].first != bd[j].first) break;
            int sub = min(ad[i].second, bd[j].second);
            ad[i].second -= sub;
            bd[j].second -= sub;
            if (ad[i].second == 0) i++;
            if (bd[j].second == 0) j++;
        }
        cout << (i == ad.size() && j == bd.size() ? "Yes" : "No") << '\n';

    }
}