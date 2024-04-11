#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
char str[1000100];
int cnt[1000100];
int pre[1000100];
int suf[1000100];

int main() {
    scanf("%s",str+1);
    n = strlen(str+1);
    for (int i=1;i<=n;i++) {
        if (str[i]=='v'&&str[i-1]=='v') cnt[i]=1;
    }
    for (int i=1;i<=n;i++) pre[i] = pre[i-1]+cnt[i];
    for (int i=n;i;i--) suf[i] = suf[i+1]+cnt[i];
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        if (str[i]=='o') {
            ans += 1LL*pre[i-1]*suf[i+1];
        }
    }
    printf("%lld\n",ans);

    return 0;
}