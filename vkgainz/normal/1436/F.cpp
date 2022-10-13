#include <bits/stdc++.h>
using namespace std;

//REMEMBER THE POWER OF PIE!!!!
long long mod = 998244353;
long long getPow(int b, long long p) {
    if(p==0)
        return 1LL;
    long long x = getPow(b, p/2);
    if(p%2) return (((x*1LL*x)%mod*b)%mod+mod)%mod;
    else return ((x*1LL*x)%mod+mod)%mod;
}
int main() {
    int m; cin >> m;
    long long numAdd[100001];
    long long in[100001];
    for(int i=0;i<m;i++) {
        long long a, freq; cin >> a >> freq;
        in[a] = freq;
    }
    vector<pair<long long, long long>> get[100001];
    for(int i=1;i<=100000;i++) {
        for(int j=i;j<=100000;j+=i) {
            if(in[j]>0) {
                get[i].push_back({j, in[j]});
            }
        }
    }
    numAdd[1] = 1;
    for(int i=1;i<=100000;i++) {
        for(int j=2*i;j<=100000;j+=i) {
            numAdd[j]-=numAdd[i];
        }
    }
    //check for overflow!
    long long ans = 0LL;
    for(int i=1;i<=100000;i++) {
        long long numElements = 0LL;
        long long sumsq = 0LL;
        long long sum = 0LL;
        for(auto &it : get[i]) {
            numElements+=it.second;
            sum+=it.second*1LL*it.first%mod;
            sum%=mod;
            sumsq+=it.second*1LL*it.first%mod*1LL*it.first%mod;
            sumsq%=mod;
        }
        if(numElements<=1) continue;
        if(numElements==2) {
            long long tot= sum*1LL*sum%mod*numAdd[i]%mod;
            ans+=tot;
            ans%=mod;
        }
        else {
            long long p = getPow(2, (numElements-3)%(mod-1))%mod;
            long long add = p; 
            numElements%=mod;
            add = add*1LL*numElements%mod;
            add = add*1LL*sum%mod*1LL*sum%mod;
            long long add2 = p;
            add2 = add2*1LL*(numElements-2)%mod;
            add2 = add2*1LL*sumsq%mod;
            long long tot = (add+add2)%mod*1LL*numAdd[i]%mod;
            ans+=tot;
            ans%=mod;
        }
    }
    if(ans<0)
        ans+=mod;
    cout << ans << "\n";
}