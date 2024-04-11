#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e7 + 5;
int cnt[N],prime[N],np[N],tot=0;
ll dp[N];

void init(int n) {
   np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           if(i%prime[j]==0) break;
       }
   }
}
int main() {
    init(N - 1);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }
    for(int i = 1; i <= tot; ++i) {
        for(int j = (N - 1) / prime[i]; j >= 1; --j) {
            cnt[j] += cnt[j * prime[i]];
        }
    }
    for(int i = N - 1; i >= 1; --i) {
        dp[i] = 1ll * cnt[i] * i;
        for(int j = 1; j <= tot; ++j) {
            if(i * prime[j] >= N) break;
            dp[i] = max(dp[i], dp[i * prime[j]] + 1ll * (cnt[i] - cnt[i * prime[j]]) * i);
        }
    }
    cout << dp[1] << '\n';
}