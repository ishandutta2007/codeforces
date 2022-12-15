#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
typedef long long ll;
map<ll,ll> cnt;
vector<ll> wew;
ll N, i, j, x;

int main(){
        for(scanf("%lld",&N),i=1;i<=N;i++){
                scanf("%lld",&x);
                cnt[x]++;
        }
        for(auto v : cnt) wew.push_back(v.second);
        sort(wew.begin(),wew.end(),[](ll i,ll j){return i>j;});
        ll ans = 0;
        for(int i=1;i<=min(20LL,(ll)wew.size());i++){
                ll mn = 1LL<<60;
                for(int j=0;j<i;j++)
                        mn=min(mn,(ll)(wew[j]/(1<<(i-j-1))));
                ans = max(ans, mn*((1<<i)-1));
        }
        printf("%lld\n",ans);
        return 0;
}