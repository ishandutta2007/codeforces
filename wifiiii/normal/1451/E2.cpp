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

int x[1<<16|5], ans[1<<16|5], vis[1<<16|5];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int lg = 31 - __builtin_clz(n);
    for(int i=2;i<=n;++i) {
        cout << "XOR " << 1 << " " << i << endl;
        cin >> x[i];
    }
    int ok = 0, r = 0, s = 0;
    vis[0] = 1;
    for(int i=2;i<=n;++i) {
        if(vis[x[i]]) {
            ok = 1;
            r = i;
            s = vis[x[i]];
            break;
        }
        vis[x[i]] = i;
    }
    if(ok) {
        // a[1] = a[ok]
        cout << "AND " << r << " " << s << endl;
        cin >> ans[r];
        for(int i=1;i<=n;++i) {
            if(i == r) continue;
            ans[i] = x[r] ^ x[i] ^ ans[r];
        }
        cout << "! ";
        for(int i=1;i<=n;++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    int a1 = 0, a2 = 0;
    for(int i=2;i<=n;++i) {
        if(x[i] == 1) a1 = i;
        if(x[i] == 2) a2 = i;
    }
    int b1 = 0, b2 = 0;
    cout << "OR " << 1 << " " << a1 << endl;
    cout << "OR " << 1 << " " << a2 << endl;
    cin >> b1 >> b2;
    int a = (b1 | b2) & ((n-1)^3);
    if(b1 >> 1 & 1) a |= 2;
    if(b2 & 1) a |= 1;
    ans[1] = a;
    for(int i=2;i<=n;++i) ans[i] = x[i] ^ ans[1];
    cout << "! ";
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}