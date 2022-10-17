
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

struct node {
    int s,k1,kno;
};
node chk(int l1,int r1,int l2,int r2) {
    if(l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if(r2 <= r1) {
        // l1 l2 r2 r1
        return {r2-l2, (r1-l1)-(r2-l2), 0};
    } else if(r1 <= l2) {
        // l1 r1 l2 r2
        return {0, r2-l1, l2-r1};
    } else if(r1 >= l2) {
        // l1 l2 r1 r2
        return {r1-l2, (r2-l1)-(r1-l2), 0};
    }
    assert(0);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        node tmp = chk(l1,r1,l2,r2);
//        cout<<tmp.s<<" "<<tmp.k1<<" "<<tmp.kno<<endl;
        if(tmp.kno) {
            ll cur=0,ans=1e18;
            for(int i=1;i<=n;++i) {
                ll now = 1ll*i*tmp.kno;
                ll k1 = 1ll*i*tmp.k1;
                if(k1 >= k) ans = min(ans, now+k);
                else ans = min(ans, now+k1+(k-k1)*2);
            }
            cout<<ans<<endl;
        } else {
            ll cur = 1ll * n * tmp.s;
            if(cur >= k) {cout<<0<<endl;continue;}
            k -= cur;
            ll k1 = 1ll * n * tmp.k1;
            if(k1 >= k) cout << k << endl;
            else cout << k1+(k-k1)*2 << endl;
        }
    }
}