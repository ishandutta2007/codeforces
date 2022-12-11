#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

map<int, int> maL, maH;
int n, a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;

    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        maL.clear();
        maH.clear();

        for(int i = 1; i <= n; i++) {
            maH[a[i]] = i; 
        }
        for(int i = n; i >= 1; i--) {
            maL[a[i]] = i;
        }

        int ans = 0;

        int lastR = 0;
        int best = 0;
        for(auto i : maL) {
            int curL = i.second, curR = maH[i.first];

            if (curL < lastR) best = 0;
            best++;
            lastR = curR;
            ans = max(ans, best);
        }
        cout << maL.size() - ans << '\n';
    }

}