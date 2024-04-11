#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int N = 1e2 + 2;
bitset<N * N> pref[N][N], suff[N][N];
int a[N];
int n;

bool special() {
    int diff = 0;
    for(int i = 1; i <= n; i++) if (a[i] != a[i - 1]) diff++;
    return diff <= 2;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (special()) {
        cout << n;
        return 0;
    }
    pref[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        pref[i][0][0] = 1;
        for(int use = 1; use <= i; use++) 
            pref[i][use] = (pref[i - 1][use - 1] << a[i]) | pref[i - 1][use];
    }
    suff[n + 1][0][0] = 1;
    for(int i = n; i >= 1; i--){
        suff[i][0][0] = 1;
        for(int use = 1; use <= n - i + 1; use++) 
            suff[i][use] = (suff[i + 1][use - 1] << a[i]) | suff[i + 1][use];
    }


    int ans = 0;
    for(int en = 1; en <= n;) {
        int st = en;
        while (en <= n && a[st] == a[en]) en++;
        for(int use = 1; use <= en - st; use++) {
            bool found = 0;
            for(int useL = 0; (!found) && useL <= use; useL++) {
                int useR = use - useL;
                for(int wL = 0; (!found) && wL <= use * a[st]; wL++) {
                    int wR = use * a[st] - wL;
                    found |= pref[st - 1][useL][wL] && suff[en][useR][wR];
                }
            }
            if (!found) ans = max(ans, use);
            else break;
        }
    }
    cout << ans;
}