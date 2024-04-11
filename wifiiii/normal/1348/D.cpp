#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a,l,r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

int a[35], ans[35];
int main() {
    int t;
    cin>>t;
    for(int i=1;i<=30;++i) a[i]=(1ll<<i+1)-1;
    while(t--) {
        int n;
        cin>>n;
        ans[0]=1;
        for(int i=1;i<=31;++i) ans[i]=1<<(i-1);
        int tp=0;
        for(;a[tp]<n;++tp);
        int d=n-a[tp-1];
        ans[tp-1]=min(ans[tp-1],d/2);
        ans[tp]=d-ans[tp-1]*2;
        cout<<tp<<endl;
        for(int i=1;i<=tp;++i) cout<<ans[i]<<" ";cout<<endl;
    }
}