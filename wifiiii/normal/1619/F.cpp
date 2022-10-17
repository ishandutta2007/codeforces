#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if(n % m == 0) {
            for(int i = 0; i < k; ++i) {
                int tot = 0;
                for(int j = 0; j < m; ++j) {
                    cout << n / m << " ";
                    for(int r = 0; r < n / m; ++r) {
                        cout << ++tot << " ";
                    }
                    cout << '\n';
                }
            }
        } else {
            int r = n % m, s = m - n % m;
            vector<int> cnt(n);
            while(k--) {
                int tot = 0;
                vector<int> ord(n);
                iota(ord.begin(), ord.end(), 0);
                sort(ord.begin(), ord.end(), [&](int i, int j) {return cnt[i] < cnt[j];});
                for(int i = 0; i < m; ++i) {
                    if(i < r) {
                        cout << n / m + 1 << " ";
                        for(int j = 0; j < n / m + 1; ++j) {
                            int p = ord[tot++];
                            cout << p + 1 << " ";
                            cnt[p]++;
                        }
                    } else {
                        cout << n / m << " ";
                        for(int j = 0; j < n / m; ++j) {
                            int p = ord[tot++];
                            cout << p + 1 << " ";
                        }
                    }
                    cout << '\n';
                }
            }
        }
    }
}