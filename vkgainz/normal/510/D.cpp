#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main() {
    int n; cin >> n;
    int l[n];
    for(int i=0;i<n;i++) cin >> l[i];
    int c[n];
    for(int i=0;i<n;i++) cin >> c[i];
    vector<int> primes[n];
    for(int i=0;i<n;i++) {
        int temp = l[i];
        for(int j=2;j*j<=temp;j++) {
            if(temp%j==0){
                while(temp%j==0) temp/=j;
                primes[i].push_back(j);
            }
        }
        if(temp>1) primes[i].push_back(temp);
    }
    ll ans = 1e15;
    for(int i=0;i<n;i++) {
        //take c[i]
        map<int,int> m;
        int v = 0;
        for(auto &it : primes[i]) m[it] = v++;
        ll dp[i+1][1<<primes[i].size()];
        for(int x=0;x<=i;x++)
            for(int y=0;y<1<<primes[i].size();y++) dp[x][y] = 1e15;
        dp[i][(1<<primes[i].size())-1] = c[i];
        for(int j=i-1;j>=0;j--) {
            int offer = 0;
            for(auto &it : primes[j]) {
                if(m.find(it)!=m.end()) offer+=1<<m[it];
            }
            for(int msk=0;msk<1<<primes[i].size();msk++) {
                dp[j][msk] = dp[j+1][msk];
            }
            for(int msk=0;msk<1<<primes[i].size();msk++) {
                dp[j][msk&offer] = min(dp[j][msk&offer],dp[j+1][msk]+c[j]);
            }
        }
        ans = min(ans,dp[0][0]);
    }
    if(ans==1e15) cout << -1 << endl;
    else cout << ans << endl;
}