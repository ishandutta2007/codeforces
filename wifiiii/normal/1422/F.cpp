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
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<ll,int> pii;

const int maxn = 200005;
const int mod = 1e9+7;
int tot=0;
int ls[maxn*152],rs[maxn*152],pos[maxn];
ll sum[maxn*152];
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
inline ll inv(ll a) {return fpow(a,mod-2);}
int update(int pre,int p,ll v,int l,int r) {
    int rt=++tot;
    ls[rt]=ls[pre],rs[rt]=rs[pre];
    sum[rt]=sum[pre]*v%mod;
    if(l<r) {
        int m=(l+r)>>1;
        if(p<=m) ls[rt]=update(ls[pre],p,v,l,m);
        else rs[rt]=update(rs[pre],p,v,m+1,r);
    }
    return rt;
}

ll query(int rt, int L, int R, int l, int r) {
    if(L <= l && r <= R) return sum[rt];
    int m = (l + r) / 2;
    ll ret = 1;
    if(L <= m) ret = ret * query(ls[rt], L, R, l, m) % mod;
    if(m < R) ret = ret * query(rs[rt], L, R, m+1, r) % mod;
    return ret;
}

int np[maxn], mp[maxn];
vector<pair<int,int>> stk[maxn];
int main() {
    for(int i=2;i<maxn;++i) {
        if(np[i]) continue;
        mp[i] = i;
        for(int j=i+i;j<maxn;j+=i) {
            np[j]=1;
            if(!mp[j]) mp[j]=i;
        }
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    sum[0]=1;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        pos[i] = pos[i-1];
        while(x != 1) {
            int p = mp[x];
            int cnt = 0;
            while(x % p == 0) x /= p, cnt++;
            int tmp = cnt;
            while(!stk[p].empty()) {
                int &lstpos = stk[p].back().first, &lstpw = stk[p].back().second;
                int mn = min(lstpw, tmp);
                tmp -= mn;
                lstpw -= mn;
                pos[i] = update(pos[i], lstpos, inv(fpow(p, mn)), 1, n);
//                cout << "upd-: " << lstpos << " " << fpow(p, mn) << endl;
                if(!lstpw) stk[p].pop_back();
                else break;
            }
            stk[p].push_back({i, cnt});
            pos[i] = update(pos[i], i, fpow(p, cnt), 1, n);
//            cout << "upd+: " << i << " " << fpow(p, cnt) << endl;
        }
    }
    cin>>m;
    int ans = 0;
    while(m--) {
        int l, r;
        cin >> l >> r;
        l = (l + ans) % n + 1;
        r = (r + ans) % n + 1;
        if(l > r) swap(l, r);
        cout << (ans = query(pos[r], l, r, 1, n)) << endl;
    }
}