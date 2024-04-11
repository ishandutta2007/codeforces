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
typedef pair<int,int> pii;

int a[200005], b[200005];
int main() {
    int n;
    cin >> n;
    int m = (4 - n % 3) % 3;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(n == 1) return cout << a[1] << endl, 0;
    vector<int> pos(n);
    iota(all(pos), 1);
    sort(all(pos), [&](int i,int j){return a[i]<a[j];});
    vector<ll> pre(n+1);
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[pos[i-1]];
    for(int i=1;i<=m;++i) b[pos[i-1]]=1;
    for(int i=m+1;i<=n;i+=3) {
        if(pre[i+2]-pre[i-1]<0) {
            b[pos[i-1]]=b[pos[i]]=b[pos[i+1]]=1;
        } else break;
    }
//    ii cout<<b[i]<<" ";cout<<endl;
    ll ans=0;
    int ok = 0;
    ll cur=0;
    for(int i=1;i<n;++i) if(b[i]==b[i+1]) ok=1;
    for(int i=1;i<=n;++i) if(b[i]) cur+=-a[i];else cur+=a[i];
    if(!ok) {
        ll tmp = -1e18;
        vector<ll> vdel,vadd;
        for(int i=1;i<=n;++i) {
            if(b[i]) vdel.push_back(2*a[i]);
            else vadd.push_back(-2*a[i]);
        }
        sort(all(vdel));
        sort(all(vadd));
        reverse(all(vdel));
        reverse(all(vadd));
        if(vdel.size() >= 3) tmp = max(tmp, vdel[0]+vdel[1]+vdel[2]);
        if(vadd.size() >= 3) tmp = max(tmp, vadd[0]+vadd[1]+vadd[2]);

        int m1 = -2e9, m2 = 2e9;
        int p1 = -1, p2 = -1;
        for(int i=1;i<=n;++i) {
            if(b[i]) {
                // -a[i] -> a[i]
                if(a[i] > m1) {
                    m1 = a[i];
                    p1 = i;
                }
            }
            else {
                // a[i] -> -a[i]
                if(a[i] < m2) {
                    m2 = a[i];
                    p2 = i;
                }
            }
        }
        tmp = max(tmp, 2ll*a[p1]-2*a[p2]);
        cur += tmp;
    }
    cout << cur << endl;
}