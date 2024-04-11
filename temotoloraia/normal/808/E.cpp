#include<bits/stdc++.h>
#define PB push_back
#define N 500005
#define LL long long
#define MP make_pair
#define F first
#define S second
using namespace std;
LL n, m, i, j, k, l, r, t, w, u, d, dp[N], ans=1;
pair<double,pair<LL,LL> >p[N];
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>p[i].S.F>>p[i].S.S;
        p[i].F=(double)p[i].S.F/p[i].S.S;
    }
    sort(p,p+n);
    dp[0]=1;l=0;
    for(i=0;i<n;i++){
        l+=p[i].S.F;
        l=min(l,m);
        r=max(p[i].S.F,l-3);
        for(j=l;j>=r;j--){
            dp[j]=max(dp[j],dp[j-p[i].S.F]+p[i].S.S);
            ans=max(ans,dp[j]);
        }
    }ans--;
    cout<<ans<<endl;
    return 0;
}