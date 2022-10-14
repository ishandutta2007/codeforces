#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
ll a[N];
int main(){
    int n,k;scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(k==1)return 0*printf("%i",n);
    sort(a+1,a+n+1);
    map<ll,int> cnt,was;
    for(int i=1;i<=n;i++)cnt[a[i]]++;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(was[a[i]]==1)continue;
        vector<int> all;
        for(ll j=a[i];j<=(ll)1e9;j*=k)all.pb(cnt[j]),was[j]=1;
        int m=(int)all.size();
        vector<int> dp(m);
        dp[0]=all[0];
        for(int j=1;j<(int)all.size();j++){
            dp[j]=max(dp[j-1],(j>1?dp[j-2]:0)+all[j]);
        }
        ans+=dp[m-1];
    }
    printf("%i",ans);
    return 0;
}