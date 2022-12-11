#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int magic = 480;

typedef long long ll;

int n;
int P[N];
int R[N];

void prepare() {
    string s;
    cin >> s;
    n = s.length();
    for(int i = 1; i <= n; i++) 
        P[i] = P[i - 1] + (s[i - 1] == '1');

    R[n + 1] = n + 1;
    for(int i = n; i >= 1; i--) {
        if (P[i] != P[i - 1]) R[i] = i;
        else R[i] = R[i + 1];
    }
}
pair<int, int> compX[N];
long long solve() {
    long long ans = 0;

    //cout << ans << endl;

    for(int st = 0; st <= n; st++) {
        int curL = st;
        for(int i = 1; i <= magic; i++) {
            curL = R[curL + 1];
            if (curL == n + 1) break;
            int curR = R[curL + 1] - 1; 
            ans += (curR - st) / i - (curL - st - 1) / i; 
            //cout << st << " " << curL << " " << curR << endl;
        }
    }
    //cout << ans << endl;


    for(int x = 0; x <= magic; x++) {
        for(int i = 0; i <= n; i++) compX[i] = {(i - P[i]) - x * P[i], P[i]};
        sort(compX, compX + n + 1);
        for(int en = 0; en <= n; ) {
            int st = en;
            while (en <= n && compX[en].first == compX[st].first) en++;
            for(int i = st, j = st - 1; i < en; i++) {
                while (j + 1 < i && compX[i].second - compX[j + 1].second > magic) j++; 
                ans += j - st + 1;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    prepare();
    cout << solve();
}