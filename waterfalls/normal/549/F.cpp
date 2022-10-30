#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int a[300013];
int sum[300013];
int cnt[1000013];
vector<int> change;

long long ans;
void solve(int l, int r) {
    if (r<=l) return;
    int m = (l+r)/2;

    // high on right
    change.clear();
    int loc = m;
    int cur = 0;
    for (int i=m+1;i<=r;i++) {
        cur = max(cur,a[i]);
        while (loc>=l && a[loc]<=cur) {
            cnt[sum[loc-1]]+=1;
            change.push_back(sum[loc-1]);
            loc-=1;
        }
        if (loc==m) continue;
        ans+=cnt[((sum[i]-cur)%k+k)%k];
    }
    for (int i: change) cnt[i] = 0;

    // high on left
    change.clear();
    loc = m+1;
    cur = 0;
    for (int i=m;i>=l;i--) {
        cur = max(cur,a[i]);
        while (loc<=r && a[loc]<cur) {
            cnt[sum[loc]]+=1;
            change.push_back(sum[loc]);
            loc+=1;
        }
        if (loc==m+1) continue;
        ans+=cnt[(sum[i-1]+cur)%k];
    }
    for (int i: change) cnt[i] = 0;

    solve(l,m);
    solve(m+1,r);
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1]+a[i]%k;
        if (sum[i]>=k) sum[i]-=k;
    }
    ans = 0;
    solve(1,n);
    printf("%lld\n",ans);

    return 0;
}