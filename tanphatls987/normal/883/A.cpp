#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second


const int N=3e5+10;

int n;
ll ne,de,ti,a[N];
ll solve(){
    ll st=1,cur=1;
    ll cov=ti/de+1;
    ll ans=0;
    while (st<=ne||cur<=n){
        if (st>ne){
            ans++;
            ll now=a[cur];
            while (cur<=n&&a[cur]-now<=ti) cur++;
            continue;
        }
        if (cur>n){
            ll mov=(ne-st)/cov+1;
            ans+=mov;
            st=ne+1;
            break;
        }
        if (de*st<a[cur]){
            ll guard=(a[cur]-1)/de;
            ll mov=(guard-st)/cov;
//            cout<<guard<<" "<<mov<<'\n';
            if (st+mov*cov>ne){
                mov=(ne-st)/cov+1;
                ans+=mov;
                st=ne+1;
                continue;
            }
            ans+=mov;
            st+=mov*cov;
        }
        ll now=min(a[cur],de*st);
//        cout<<now<<'\n';
        st=(now+ti)/de+1;
        while (cur<=n&&a[cur]-now<=ti) cur++;
        ans++;
    }
    return ans;
}
int main(){
    cin>>ne>>n>>de>>ti;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<solve()<<'\n';
}