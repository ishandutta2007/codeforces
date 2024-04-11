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

ll a[105];
vector<int> g[105];
int deg[105],nxt[105];

int main() {
    int n;
    cin >> n;
    ii cin >> a[i];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(j == i) continue;
            if(a[i] % 3 == 0 && a[i] / 3 == a[j]) g[i].push_back(j), nxt[i]=j, deg[j]++;
            if(a[i] * 2 == a[j]) g[i].push_back(j), nxt[i]=j, deg[j]++;
        }
    }
    int rt=0;
    for(int i=1;i<=n;++i) if(!deg[i]) rt=i;
    for(int i=1;i<=n;++i) {
        cout<<a[rt]<<" ";
        rt=nxt[rt];
    }
    cout<<endl;
}