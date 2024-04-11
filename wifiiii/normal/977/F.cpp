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

int a[200005],cnt[400005],pos[400005],lst[400005];
int main() {
    int n;
    cin>>n;
    ii cin>>a[i];
    vi v;ii v.pb(a[i]),v.pb(a[i]+1);sort(all(v));v.resize(unique(all(v))-v.begin());
    ii a[i]=lower_bound(all(v),a[i])-v.begin()+1;
    int mx = 0, mi = 0;
    ii
    {
        cnt[a[i]] = cnt[a[i]-1] + 1;
        lst[i] = pos[a[i]-1];
        pos[a[i]] = i;
        if(cnt[a[i]] > mx) {
            mx = cnt[a[i]];
            mi = i;
        }
    }
    cout << mx << endl;
    vi ans;
    while(mi) {
        ans.pb(mi);
        mi = lst[mi];
    }
    reverse(all(ans));
    for(int i:ans) cout<<i<<" ";cout<<endl;
}