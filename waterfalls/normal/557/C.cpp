#include <cstdio>
#include <algorithm>

using namespace std;

pair<int,int> l[100013];
int sum[100013];
int num[213];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&l[i].first);
    for (int i=0;i<n;i++) scanf("%d",&l[i].second);
    sort(l,l+n);
    reverse(l,l+n);
    for (int i=n-1;i>=0;i--) sum[i] = sum[i+1]+l[i].second;
    for (int i=0;i<n;i++) num[l[i].second]+=1;
    int ans = 1e9;
    for (int i=0;i<n;i++) {
        num[l[i].second]-=1;
        if (l[i].first!=l[i+1].first) {
            int cnt = 0;
            while (cnt<=i && l[i-cnt].first==l[i].first) cnt+=1;
            int cur = 0;
            cur+=sum[0]-sum[i-cnt+1];
            cur+=sum[i+1];
            int left = cnt-1;
            for (int j=200;j>=0 && left>0;j--) {
                if (num[j]>=left) {
                    cur-=j*left;
                    left = 0;
                } else {
                    cur-=j*num[j];
                    left-=num[j];
                }
            }
            ans = min(ans,cur);
        }
    }
    printf("%d\n",ans);
}