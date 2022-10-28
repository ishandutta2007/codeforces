#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long solve(int zs, int zzs, int oos, multiset<int> &central_zs) {
    if (oos > 0) {
        auto it = central_zs.upper_bound(1);
        if (it != central_zs.end() || zzs > 0) {
            if (it != central_zs.end()) {
                central_zs.insert(*it - 1);
                central_zs.erase(it);
            } else --zzs;
            return a + b + solve(zs, zzs, oos - 1, central_zs);
        } else if ((central_zs.contains(1) || zs > 0) && b - c > 0) {
            if (central_zs.contains(1)) {
                central_zs.erase(central_zs.begin());
                ++oos;
            } else --zs;
            return b - c + solve(zs, zzs, oos - 1, central_zs); 
        } else return 0;
    } else if (central_zs.contains(1) && b - c > 0) {
        central_zs.erase(central_zs.begin());
        ++oos;
        return b - c + solve(zs, zzs, oos - 1, central_zs);
    } else if (central_zs.upper_bound(1) != central_zs.end() || zzs > 0) {
        return a;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> a >> b >> c >> s;

        int zs = 0, zzs = 0, oos = 0;
        multiset<int> central_zs;

        for (int i = 0, j = 0; i < n; i = j) {
            while (s[i] == s[j]) ++j;
            if (s[i] == '0') {
                if (i == 0 || j == n) {
                    zzs += j - i - 1, ++zs;
                } else {
                    central_zs.insert(j - i);
                }
            } else {
                oos += j - i - 1;
            }
        }

        multiset<int> temp_zzs = central_zs;

        cout << max(
            oos > 0 ? b + solve(zs, zzs, oos - 1, temp_zzs) : 0LL, 
            solve(zs, zzs, oos, central_zs)
        ) << "\n";
    }
}