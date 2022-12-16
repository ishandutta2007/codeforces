#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5+5;
ll arr[MN], tot, N, i;
vector<int> ans;
map<ll,ll> cnt;
int main(){
        for(scanf("%lld",&N),i=1;i<=N;i++){
                scanf("%lld",&arr[i]);
                tot += arr[i]; cnt[arr[i]]++;
        }
        for(i=1;i<=N;i++){
                cnt[arr[i]]--;
                if((tot-arr[i])%2==0){
                        if(cnt[(tot-arr[i])/2]>0)
                                ans.push_back(i);
                }
                cnt[arr[i]]++;
        }
        printf("%d\n",ans.size());
        for(auto v: ans) printf("%d ",v);
        return 0;
}