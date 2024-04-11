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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r)    for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qq

int cnt[25];
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        for(int j=20;j>=0;--j) {
            if(x>>j&1) cnt[j]++;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        ll tmp = 0;
        for(int j=20;j>=0;--j) {
            if(cnt[j]) tmp += 1<<j, cnt[j]--;
        }
        ans += tmp * tmp;
    }
    cout << ans << endl;
}