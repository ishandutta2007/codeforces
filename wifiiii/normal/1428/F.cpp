#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
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

int tot=0;
const int maxn = 500005;
ll cnt[maxn<<2], s[maxn<<2],lz[maxn<<2];
void update(int pos,int val,int l,int r,int rt) {
    if(l == r) {
        cnt[rt] += val;
        s[rt] += 1ll * val * l;
        return;
    }
    if(lz[rt]) {
        cnt[rt<<1] = 0;
        cnt[rt<<1|1] = 0;
        s[rt<<1] = 0;
        s[rt<<1|1] = 0;
        lz[rt<<1] = 1;
        lz[rt<<1|1] = 1;
        lz[rt] = 0;
    }
    int m = (l + r) >> 1;
    if(pos <= m) update(pos, val, l, m, rt<<1);
    else update(pos, val, m+1, r, rt<<1|1);
    s[rt] = s[rt<<1] + s[rt<<1|1];
    cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
}
void clear(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) {
        s[rt] = 0;
        cnt[rt] = 0;
        lz[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    if(lz[rt]) {
        cnt[rt<<1] = 0;
        cnt[rt<<1|1] = 0;
        s[rt<<1] = 0;
        s[rt<<1|1] = 0;
        lz[rt<<1] = 1;
        lz[rt<<1|1] = 1;
        lz[rt] = 0;
    }
    if(m >= L) clear(L,R,l,m,rt<<1);
    if(m < R) clear(L,R,m+1,r,rt<<1|1);
    s[rt] = s[rt<<1] + s[rt<<1|1];
    cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
}
ll query(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) return cnt[rt];
    int m = (l + r) >> 1;
    if(lz[rt]) {
        cnt[rt<<1] = 0;
        cnt[rt<<1|1] = 0;
        s[rt<<1] = 0;
        s[rt<<1|1] = 0;
        lz[rt<<1] = 1;
        lz[rt<<1|1] = 1;
        lz[rt] = 0;
    }
    ll ret = 0;
    if(m >= L) ret += query(L,R,l,m,rt<<1);
    if(m < R) ret += query(L,R,m+1,r,rt<<1|1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string t;
    cin>>t;
    int lst=0,m1=0;
    ll ans=0;
    for(int i=1;i<=n;++i) {
        int x=t[i-1]-'0';
        if(x) {
            int c=i-lst;
            ans+=1ll*c*(c+1)/2;
            m1++;
        } else {
            for(int r=0;r<=i-1-lst;++r) update(r, 1, 0, n, 1);
            m1=0;
            lst=i;
        }
        if(m1) {
            int tmp=query(0,m1,0,n,1);
            clear(0,m1,0,n,1);
            update(m1,tmp,0,n,1);
        }
        ans+=s[1];
    }
    cout<<ans<<endl;
}