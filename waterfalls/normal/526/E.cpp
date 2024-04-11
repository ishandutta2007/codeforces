#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n,q;
int a[3000013];
long long sums[3000013];
int to[2000013];
map<long long,int> memo;

int check(int start) {
    int where = start;
    int cur = 0;
    while (where<start+n) where = to[where]+1, cur+=1;
    return cur;
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) a[i+n] = a[i], a[i+2*n] = a[i];
    for (int i=1;i<=3*n;i++) sums[i] = sums[i-1]+a[i-1];
    for (int Q=0;Q<q;Q++) {
        long long b;
        scanf("%I64d",&b);
        if (memo.count(b)) {
            printf("%d\n",memo[b]);
            continue;
        }
        int cur = 0;
        for (int i=0;i<2*n;i++) {
            while (sums[cur+2]-sums[i]<=b) cur+=1;
            to[i] = cur;
        }
        int minLen = n+2;
        int best = 0;
        for (int i=0;i<n;i++) if (to[i]-i+1<minLen) minLen = to[i]-i+1,best = i;
        int ans = n+2;
        minLen+=1;
        for (int i=best;i!=best+minLen;i=i+1) ans = min(ans,check(i%n));
        memo[b] = ans;
        printf("%d\n",ans);
    }

    return 0;
}