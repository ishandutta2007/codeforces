#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;
#define int ll
int32_t main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int s=0;
    for(int i=0;i<n;++i) cin>>a[i],s+=a[i];
    sort(all(a));
    reverse(all(a));
    if(s<m) return cout<<-1<<endl,0;
    int lo=1,hi=n;
    while(lo<hi) {
        int mid=(lo+hi)/2,tot=0;
        vector<int> cnt(mid);
        for(int i=0;i<n;++i) {
            tot+=max(0ll,a[i]-cnt[i%mid]);
            cnt[i%mid]++;
        }
        if(tot>=m) hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<endl;
}