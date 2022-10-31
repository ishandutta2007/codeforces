#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n;
vector<int> arr[1000000];
lli prob[1000100], iv[1000100];

const lli MOD = 998244353;

lli power(int a,int p) {
    if(p==0) return 1;
    else if(p&1) return power(a,p-1)*a % MOD;
    else {
        lli ret = power(a,p/2);
        return ret*ret % MOD;
    }
}
lli inv(int a) { return power(a, MOD-2); }

int main() {
    iv[0] = iv[1] = 1;
    for(int i=2;i<=1000000;i++) iv[i] = inv(i);

    scanf("%d",&n);
    for(int i=0,s,k;i<n;i++) {
        scanf("%d",&s);
        while(s--) {scanf("%d",&k), arr[i].push_back(k);}
        for(auto &it:arr[i]) prob[it] = (prob[it] + iv[n] * iv[arr[i].size()] % MOD) % MOD;
    }
    lli ans=0;
    for(int i=0;i<n;i++) {
        for(auto &it:arr[i]) ans = (ans + iv[n] * prob[it] % MOD) % MOD;
    }
    printf("%lld\n",ans);
    
    return 0;
}