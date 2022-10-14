#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
const ll mod = 1e9 + 7;
void solve() {

    int h, m;
    scanf("%d%d", &h, &m);
    int res = 20 * 60;
    int timeLeft = res - (h*60 + m);
    int H, D, C, N;
    scanf("%d%d%d%d", &H, &D, &C, &N);
    if(timeLeft <= 0) {
        double left = H;
        double disc = C * 0.8;
        double toDelete = (H + N - 1) / N;
        printf("%.10f", toDelete * disc);
    } else {
        int left = H + (D * timeLeft);
        
        // two choices
        double ans = 1e18;
        double disc = C * 0.8;
        ans = min( ((left + N - 1) / N )* disc ,( (H + N - 1) /  N) * (double)C);
        printf("%.10f", ans);

    }
}

int main() {

    int t = 1, i = 1;
    //scanf("%d", &t);
    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}