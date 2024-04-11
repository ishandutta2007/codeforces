#include <bits/stdc++.h>
using namespace std;
//#define ll long long
const int N=300050;
#define ldb long double
ldb a[N];
ldb suf[N];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    map<ldb,int> cnt;
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i],cnt[a[i]]++;
    ldb ans=0;
    for(int i=1;i<=n;i++){
        cnt[a[i]]--;
        ldb S=suf[i+1];
        S-=cnt[a[i]+1]*(a[i]+1);
        S-=cnt[a[i]-1]*(a[i]-1);
        ldb j=n-i-cnt[a[i]+1]-cnt[a[i]-1];
        ans+=S-j*a[i];
    }
    cout<<fixed<<setprecision(0)<<ans;
    return 0;
}