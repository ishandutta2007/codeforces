#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, i, a, b, k;

int main(){
        for(scanf("%lld",&t),i=1;i<=t;i++){
                scanf("%lld%lld%lld",&a,&b,&k);
                if(k%2==0) printf("%lld\n",(a-b)*(k/2));
                else printf("%lld\n",(a-b)*((ll)k/2LL)+a);
        }
        return 0;
}