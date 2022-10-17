#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1, MA = 1e6;

bool prime[MA];
map<int, int> cnt[MN];
int val[MN];
void build(){
    ms(prime, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= MA; ++i){
        if (!prime[i]) continue;
        for (int j = i * i; j <= MA; j += i){
            prime[j] = 0;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    build();
    int T; cin >> T;
    while (T--){
        int N, E; cin >> N >> E;
        for (int i = 0; i <= N; ++i){
            cnt[i].clear();
            val[i] = 0;
            cnt[i][0] = 1;
        }
        ll ans = 0;
        for (int i = 0; i < N; ++i){
            int a; cin >> a;
            int idx = i % E;
            if (a == 1){
                if (cnt[idx].count(val[idx] - 1)){
                    ans += cnt[idx][val[idx] - 1];
                }
                cnt[idx][val[idx]]++;   
            }
            else if (prime[a]){
                ans--;
                val[idx]++;
                if (cnt[idx].count(val[idx] - 1)){
                    ans += cnt[idx][val[idx] - 1];
                }
                cnt[idx][val[idx]]++;
            }
            else{
                cnt[idx].clear();
                val[idx] = 0;
                cnt[idx][0] = 1;
            }
        }
        cout << ans << '\n';
    }
}