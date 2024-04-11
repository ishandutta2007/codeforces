#include <bits/stdc++.h>
using namespace std;

const int B = 400, MAX = 200000;

char str[MAX + 100];
int n,cnt[MAX*B + MAX + 100],ps[MAX + 100];

int main() {
    scanf("%s", str+1);
    n = strlen(str+1);

    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + str[i] - '0';
    
    const int BASE = B * n;
    long long ans = 0;
    for(int k=1; k<=B; k++) {
        for(int i=0;i<=n;i++) {
            int val = i - k * ps[i] + BASE;
            ans -= (1ll * cnt[val] * (cnt[val]-1)) / 2;
            cnt[val]++;
            ans += (1ll * cnt[val] * (cnt[val]-1)) / 2;
        }
        for(int i=0; i<=n; i++) {
            int val = i - k * ps[i] + BASE;
            cnt[val]--;
        }
    }

    vector<int> ones;
    for(int i=1;i<=n;i++) if(str[i]=='1') ones.push_back(i);
    for(int i=0;i<=n;i++) {
        auto it = lower_bound(ones.begin(), ones.end(), i + 1);
        for(int c=1; i + (B+1) * c <= n && it!=ones.end(); c++, it++) {
            int ni = max(i + (B+1) * c, *it + (c - (*it-i) % c)%c);
            if(next(it) != ones.end() && ni < *next(it)) {
                ans += (*next(it) - ni - 1) / c + 1;
            } else if(next(it) == ones.end() && ni <= n) {
                ans += (n - ni) / c + 1;
            }
        }
    }

    printf("%lld\n",ans);

    return 0;
}