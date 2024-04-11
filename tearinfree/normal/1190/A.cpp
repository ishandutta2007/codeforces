#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

lli n;
int m;
lli k;
lli arr[100001];

int main() {
    scanf("%lld%d%lld",&n,&m,&k);
    for(int i=0;i<m;i++) scanf("%lld",arr+i);

    lli cnt=0,ans=0;
    for(int i=0,j=0;i<m;i=j) {
        lli v=(arr[i]-cnt-1)/k*k;
        for(;j<m && arr[j]-cnt<=v+k;j++);
        cnt += j-i;
        ans++;
    }
    printf("%lld\n",ans);
    
    return 0;
}