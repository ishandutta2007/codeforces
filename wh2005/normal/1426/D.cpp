#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+9;
int n,a[N],sum[N];
map<int ,int >mp;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int ans=0,sum=0;mp[0]=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(mp[sum]==1){
            ans++;sum=a[i];
            mp.clear();
            mp[0]=1,mp[sum]=1;
        }
        else mp[sum]=1;
    }
    printf("%lld\n",ans);
    return 0;
}