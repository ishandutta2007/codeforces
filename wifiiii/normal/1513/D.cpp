#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,p;
        cin>>n>>p;
        vector<int> l(n),r(n),a(n),ord(n),vis(n);
        for(int i=0;i<n;++i) cin>>a[i],ord[i]=i;
        sort(ord.begin(),ord.end(),[&](int i,int j){return a[i]<a[j];});
        ll ans=1ll*(n-1)*p;
        for(int i:ord) {
            if(vis[i]) continue;
            vis[i]=1;
            l[i]=r[i]=i;
            for(int j=i+1;j<n;++j) {
                if(a[j]%a[i]) break;
                r[i]=j;
                if(vis[j]) break;
                vis[j]=1;
            }
            for(int j=i-1;j>=0;--j) {
                if(a[j]%a[i]) break;
                l[i]=j;
                if(vis[j]) break;
                vis[j]=1;
            }
            if(a[i]<p && r[i]!=l[i]) {
                int len=r[i]-l[i]+1;
                ans-=1ll*(len-1)*p;
                ans+=1ll*(len-1)*a[i];
            }
        }
        cout<<ans<<endl;
    }
}