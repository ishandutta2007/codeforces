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

const int maxn = 200005;
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}

ll sum[maxn<<2], pmx[maxn<<2], mx[maxn<<2], lz[maxn<<2];
inline void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    pmx[rt] = max(pmx[rt<<1], sum[rt<<1] + pmx[rt<<1|1]);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
        mx[rt] = pmx[rt] = sum[rt] = read();
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    pushup(rt);
}
inline void upd(int l, int r, int rt, ll x) {
    lz[rt] = x, mx[rt] = x, sum[rt] = pmx[rt] = x * (r-l+1);
}
inline void pushdown(int l, int r, int rt) {
    if(lz[rt]) {
        int m=(l+r)/2;
        upd(l,m,rt<<1,lz[rt]);
        upd(m+1,r,rt<<1|1,lz[rt]);
        lz[rt]=0;
    }
}
void update(int L,int R,ll x,int l,int r,int rt) {
    if(L <= l && r <= R) {
        upd(l,r,rt,x);
        return;
    }
    pushdown(l,r,rt);
    int m = (l + r) >> 1;
    if(m >= L) update(L, R, x, l, m, rt<<1);
    if(m < R) update(L, R, x, m+1, r, rt<<1|1);
    pushup(rt);
}
ll qry(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) return sum[rt];
    pushdown(l,r,rt);
    int m = (l + r) >> 1;
    ll ans = 0;
    if(m >= L) ans += qry(L, R, l, m, rt<<1);
    if(m < R) ans += qry(L, R, m+1, r, rt<<1|1);
    return ans;
}
int cnt = 0;
int last_greater_than_x(int L,int R,ll x,int l,int r,int rt) {
    if(mx[rt] <= x) return -1;
    if(l == r) return l;
    ++cnt;
    pushdown(l,r,rt);
    int m = (l + r) >> 1;
    if(m < R && mx[rt<<1|1] > x) return last_greater_than_x(L, R, x, m+1, r, rt<<1|1);
    if(m >= L && mx[rt<<1] > x) return last_greater_than_x(L, R, x, l, m, rt<<1);
    return -1;
}

int first_prefix_greater_than_x(int L,int R,ll x,ll &cur,int l,int r,int rt) {
    if(l == r) {
        if(cur + sum[rt] > x) return l;
        cur += sum[rt];
        return -1;
    }
    if(L <= l && r <= R && cur + pmx[rt] <= x) {
        cur += sum[rt];
        return -1;
    }
    ++cnt;
    pushdown(l,r,rt);
    int m = (l + r) >> 1;
    if(m >= L) {
        int lans = first_prefix_greater_than_x(L, R, x, cur, l, m, rt<<1);
        if(lans == -1 && m < R) {
            int rans = first_prefix_greater_than_x(L, R, x, cur, m+1, r, rt<<1|1);
            return rans;
        }
        return lans;
    }
    return first_prefix_greater_than_x(L, R, x, cur, m+1, r, rt<<1|1);
}
int main() {
    int n = read(), q = read();
    build(1, n, 1);
    while(q--) {
        int op = read(), x = read();
        ll y = read();
        if(op == 1) {
            int pos = last_greater_than_x(1, x, y, 1, n, 1);
            if(pos == -1) {
                update(1, x, y, 1, n, 1);
            } else if(pos < x) update(pos+1, x, y, 1, n, 1);
        } else {
            int pos = last_greater_than_x(x, n, y, 1, n, 1), ans = 0;
            if(pos == -1) pos = x;
            else pos++;
            while(pos <= n) {
                ll cur = 0;
                cnt = 0;
                int nxt = first_prefix_greater_than_x(pos, n, y, cur, 1, n, 1);
                if(nxt == -1) {
                    ans += n + 1 - pos;
                    pos = n + 1;
                } else {
                    y -= qry(pos, nxt-1, 1, n, 1);
                    ans += nxt - pos;
                    cnt = 0;
                    pos = last_greater_than_x(nxt, n, y, 1, n, 1) + 1;
                }
            }
            printf("%d\n", ans);
        }
    }
}