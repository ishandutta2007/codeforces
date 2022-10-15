#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=1000007;
int n,a[maxn],s[maxn];
 
int get_ans(int u){
    int ans=0;
    for (int i=1;i<=n;++i){
        ans+=min(s[i]%u,u-s[i]%u);
    }
    return ans;
}
 
#undef int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    if (s[n]==1) {cout<<-1<<endl; return 0;}
    long long sum=s[n],q=sqrt(sum),ans=1e18;
    for (int i=2;i<=q;++i){
        if (sum%i==0){
            ans=min(get_ans(i),ans);
            while (sum%i==0) sum/=i;
        }
    }
    if (sum>1) ans=min(get_ans(sum),ans);
    cout<<ans<<endl;
    return 0;
}