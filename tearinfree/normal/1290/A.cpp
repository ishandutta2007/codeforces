#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,k,arr[4000];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++) scanf("%d",arr+i);

        k = min(k,m-1);

        int ans = 0;
        for(int s=0;s<=k;s++) {
            int f=n-(k-s)-1;

            int rem = m-k-1, mx = 1e9;
            for(int a=0;a<=rem;a++) {
                int st=s+a, fi=f-(rem-a);
                mx = min(mx, max(arr[st],arr[fi]));
            }
            ans = max(ans, mx);
        }
        printf("%d\n",ans);
    }
    return 0;
}