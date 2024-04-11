#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

ll a[300005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int n=n1+n2+n3;
    ll mn1=1e9,mn2=1e9,mn3=1e9,s1=0,s2=0,s3=0;
    for(int i=1;i<=n;++i) cin>>a[i];
    ll s=0;
    for(int i=1;i<=n;++i) {
        s+=a[i];
        if(i<=n1) {
            mn1=min(mn1,a[i]);
            s1+=a[i];
        } else if(i<=n2+n1) {
            mn2=min(mn2,a[i]);
            s2+=a[i];
        } else {
            mn3=min(mn3,a[i]);
            s3+=a[i];
        }
    }
    ll ans = s-2*(mn1+mn2+mn3-max(mn1,max(mn2,mn3)));
    ans = max(ans, s-2*min(s1,min(s2,s3)));
    if(n1 == 1) {
        ans=max(ans, s-2*a[1]);
    }
    if(n2 == 1) {
        ans=max(ans, s-2*a[n1+1]);
    }
    if(n3 == 1) {
        ans=max(ans, s-2*a[n2+n1+1]);
    }
    if(n1 == 2) {
        ans=max(ans, s-2*a[1]-2*a[2]);
    }
    if(n2 == 2) {
        ans=max(ans, s-2*a[n1+1]-2*a[n1+2]);
    }
    if(n3 == 2) {
        ans=max(ans, s-2*a[n2+n1+1]-2*a[n2+n1+2]);
    }
    cout << ans << endl;
}