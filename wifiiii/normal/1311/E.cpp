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

int fa[5005], dep[5005];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int max_dep = n*(n-1)/2;
        if(d > max_dep) {
            cout << "NO\n";
            continue;
        }
        int mx = 0;
        for(int i=2;i<=n;++i) fa[i]=i/2,dep[i]=dep[fa[i]]+1,mx=max(mx,dep[i]);
        int min_dep = 0;
        for(int i=1;i<=n;++i) min_dep += dep[i];
        if(d < min_dep) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int cur = min_dep, need = d - cur, lst = 1<<(31-__builtin_clz(n));
        for(int i=n;i>=1;--i) {
            if(!need) break;
            if(__builtin_popcount(i) == 1) continue;
            // ...
            int f = fa[i], df = dep[f], dd = dep[lst] - dep[f];
            if(need <= dd) {
                int tp = dd - need;
                int ff = lst;
                while(tp--) ff = fa[ff];
                fa[i] = ff;
                dep[i] = dep[ff] + 1;
                break;
            } else {
                fa[i] = lst;
                dep[i] = dep[lst] + 1;
                need -= dd;
            }
            lst = i;
        }
        int sum = 0;
        for(int i=2;i<=n;++i) {
            cout<<fa[i]<<" ";
            assert(dep[i] == dep[fa[i]] + 1);
            sum += dep[i];
        }
        cout<<endl;
        assert(sum == d);
    }
}