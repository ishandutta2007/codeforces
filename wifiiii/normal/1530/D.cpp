#include<bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), cnt(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i], cnt[a[i]]++;
        vector<int> aa = a;
        while(1) {
            a = aa;
            int ok = 1, ans = n;
            vector<int> unvis, cntt = cnt;
            for(int i = 0; i < n; ++i) {
                if(!cntt[i]) unvis.push_back(i);
            }
            vector<int> ord(n);
            iota(ord.begin(), ord.end(), 0);
            shuffle(unvis.begin(), unvis.end(), mrand);
            shuffle(ord.begin(), ord.end(), mrand);
            for(int j : ord) {
                int i = ord[j];
                if(cntt[a[i]] > 1) {
                    if(i == unvis.back()) {
                        if(unvis.size() == 1) {
                            ok = 0;
                            break;
                        }
                        --cntt[a[i]];
                        a[i] = unvis[unvis.size() - 2];
                        unvis.erase(unvis.end() - 2);
                        ++cntt[a[i]];
                    } else {
                        --cntt[a[i]];
                        a[i] = unvis.back();
                        unvis.pop_back();
                        ++cntt[a[i]];
                    }
                    --ans;
                }
            }
            if(!ok) continue;
            cout << ans << '\n';
            for(int i : a) cout << i + 1 << " ";
            cout << '\n';
            break;
        }
    }
}