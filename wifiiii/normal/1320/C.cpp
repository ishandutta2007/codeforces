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
#define endl '\n'
#define int ll
struct node {
    int x,y,z;
    bool operator < (const node & n) const {
        return x < n.x;
    }
}a[200006];
const int maxn = 1000005;
struct node2 {
    int w,v;
    bool operator < (const node2 & n) const {
        return w < n.w;
    }
}b[200005],c[200005];

ll lz[maxn<<2], mx[maxn<<2];
int d[maxn];
void build(int l,int r,int rt) {
    if(l==r) {
        mx[rt] = -d[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
void update(int L,int R,int x,int l,int r,int rt) {
    if(L<=l && r<=R) {
        lz[rt] += x;
        mx[rt] += x;
        return;
    }
    if(lz[rt]) {
        lz[rt<<1] += lz[rt], lz[rt<<1|1] += lz[rt];
        mx[rt<<1] += lz[rt], mx[rt<<1|1] += lz[rt];
        lz[rt] = 0;
    }
    int m=(l+r)/2;
    if(L<=m) update(L,R,x,l,m,rt<<1);
    if(R> m) update(L,R,x,m+1,r,rt<<1|1);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}
inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int32_t main() {
    int n=read(),m=read(),p=read();
    for(int i=1;i<=n;++i) {
        b[i].w=read();
        b[i].v=read();
    }
    sort(b+1,b+1+n);
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;++i) {
        int w=read(),v=read();
        d[w]=min(d[w],v);
    }
    for(int i=maxn-2;i>=0;--i) d[i]=min(d[i+1],d[i]);
//    for(int i=0;i<=6;++i) cout<<d[i]<<" ";cout<<endl;
    int N = maxn-1;
    build(1,N,1);
    for(int i=1;i<=p;++i) {
        a[i].x=read();
        a[i].y=read();
        a[i].z=read();
    }
    sort(a+1,a+1+p);
    int cur = 1;
    ll ans = -1e18;
    for(int i=1;i<=n;++i) {
//        cout << "i: " << i << endl;
        while(cur<=p && a[cur].x < b[i].w) {
//            cout << "update " << a[cur].y+1 << " " << a[cur].z << endl;
            update(a[cur].y+1, N, a[cur].z, 1, N, 1);
            ++cur;
        }
//        cout << "mx: " << mx[1] << " " << "value: " << b[i].v << endl;
        ans = max(ans, mx[1]-b[i].v);
    }
    printf("%lld\n",ans);
}