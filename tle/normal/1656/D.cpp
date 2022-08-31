#include <bits/stdc++.h>
using namespace std;
int T; typedef long long ll;
ll n;
int main() {
    scanf("%d",&T);
    while(T--) {
//        ++n;
        scanf("%lld",&n);
        ll aa=-1;
        for(ll k=2;;k<<=1) {
            ll s=k*(k+1)/2;
            if(s>n) break;
            if((n-s)%k==0) {
                aa=k; break;
            }
        }
        ll u=n;
        while(u%2==0) u>>=1;
        for(ll k=u;k<u+2;++k) {
            if(k>2e9||k<=1) continue;
            ll s=k*(k+1)/2;
            if(s>n) break;
            if((n-s)%k==0) {
                aa=k; break;
            }
        }
        printf("%lld\n",aa);
    }
}