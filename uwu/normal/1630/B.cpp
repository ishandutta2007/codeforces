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
        int N, K; cin >> N >> K;
        for (int i = 1; i <= N; ++i) cnt[i] = 0;
        for (int i = 1; i <= N; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 1; i <= N; ++i) cnt[i] += cnt[i - 1];
        int lo = 1, hi = N, mid, could;
        while (lo < hi){
            mid = (lo + hi) >> 1;
            bool good = 0;
            for (int i = 1; i + mid - 1 <= N; ++i){
                int c = cnt[i + mid - 1] - cnt[i - 1];
                if (2 * c - N >= K) good = 1, could = i;
            }
            if (good) hi = mid;
            else lo = mid + 1;
        }
        for (int i = 1; i + lo - 1 <= N; ++i){
            int c = cnt[i + lo - 1] - cnt[i - 1];
            if (2 * c - N >= K) could = i;
        }
        int x = could, y = could + lo - 1;
        cout << x << " " << y << '\n';
        int last = 1, cnt = 0;
        for (int i = 1; i <= N; ++i){
            cnt += ((a[i] >= x && a[i] <= y) ? 1 : -1);
            if ((cnt == 1 && K != 1) || i == N){
                cout << last << " " << i << '\n';
                last = i + 1;
                K--;
                cnt = 0;
            }
        }
        // cout << '\n';
    }
}