#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

struct node {
    int x,p;
    bool operator < (const node & n) const {
        return x < n.x;
    }
}a[200005];
int stk[200005],tp=0;
int nxt[200005];
int main()
{
    int d,n,m;
    cin>>d>>n>>m;
    ll ans=0;
    for(int i=1;i<=m;++i) cin>>a[i].x>>a[i].p;
    sort(a+1,a+1+m);
    a[m+1] = {d, 0};
    for(int i=m+1;i>=1;--i)
    {
        while(tp && a[stk[tp]].p > a[i].p) --tp;
        nxt[i] = stk[tp];
        stk[++tp] = i;
    }
    for(int i=0;i<=m;++i) if(a[i+1].x - a[i].x > n) return cout<<-1<<endl,0;
    int cur = n - a[1].x;
    for(int i=1;i<=m;++i)
    {
        ans += 1ll * max(min(n, a[nxt[i]].x - a[i].x) - cur, 0) * a[i].p;
        cur += max(min(n, a[nxt[i]].x - a[i].x) - cur, 0);
        cur -= a[i+1].x - a[i].x;
    }
    cout << ans << endl;
}