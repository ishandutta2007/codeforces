#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int main() {
    int n,p;
    scanf("%d%d",&n,&p);
    
    for(int k=1;k<=1000;k++) {
        lli val = 1ll*n - k*p, t = val;
        if(val>0) {
            int cnt=0;
            while(val) cnt+=val&1, val>>=1;
            if(cnt <= k && k <= t) {
                printf("%d\n",k);
                return 0;
            }
        }
    }
    puts("-1");

    return 0;
}