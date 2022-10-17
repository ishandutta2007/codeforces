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

int solve(vector<int> a) {
    int ok = 0, n = a.size(), mx = 0, mxx = 0;
    for(int i=0;i<n;++i) mxx=max(mxx,a[i]);
    unordered_map<int,int> cnt;
    for(int i:a) cnt[i]++;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n-1;++j) {
            // (0,i] (i,j] (j,n)
            int mx1=0,mn2=1e9,mx3=0;
            for(int k=0;k<=i;++k) mx1=max(mx1,a[k]);
            for(int k=i+1;k<=j;++k) mn2=min(mn2,a[k]);
            for(int k=j+1;k<n;++k) mx3=max(mx3,a[k]);
            if(mx1 == mn2 && mn2 == mx3) {
                ok = 1;
                mx = max(mx, mx1);
            }
        }
    }
    return ok;
}

const int maxn = 200005;
int mx[maxn<<2], mn[maxn<<2];
vector<int> a;
void build(int l, int r, int rt) {
    if(l == r) {
        mx[rt] = mn[rt] = a[l-1];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
int first_greater_than_x(int L,int R,int x,int l,int r,int rt) {
    if(l == r) return mx[rt] > x ? l : -1;
    if(mx[rt] <= x) return -1;
    int m = (l + r) >> 1;
    if(m >= L) {
        int lans = first_greater_than_x(L, R, x, l, m, rt<<1);
        if(lans == -1 && m < R) return first_greater_than_x(L, R, x, m+1, r, rt<<1|1);
        return lans;
    }
    return first_greater_than_x(L, R, x, m+1, r, rt<<1|1);
}
int last_greater_than_x(int L,int R,int x,int l,int r,int rt) {
    if(l == r) return mx[rt] > x ? l : -1;
    if(mx[rt] <= x) return -1;
    int m = (l + r) >> 1;
    if(m < R) {
        int rans = last_greater_than_x(L, R, x, m+1, r, rt<<1|1);
        if(rans == -1 && m >= L) return last_greater_than_x(L, R, x, l, m, rt<<1);
        return rans;
    }
    return last_greater_than_x(L, R, x, l, m, rt<<1);
}
int query_min(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) return mn[rt];
    int ret = 1e9;
    int m = (l + r) / 2;
    if(L <= m) ret = min(ret, query_min(L, R, l, m, rt<<1));
    if(m < R) ret = min(ret, query_min(L, R, m+1, r, rt<<1|1));
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        a.resize(n);
        int Mx = 0;
        unordered_map<int,int> mp;
        unordered_map<int,int> posl, posr;
        for(int i=0;i<n;++i) {
            cin>>a[i];
            Mx = max(Mx, a[i]);
            mp[a[i]]++;
            if(!posl.count(a[i])) posl[a[i]] = i;
            posr[a[i]] = i;
        }
        build(1, n, 1);
        int ok = 0;
        if(mp[Mx] >= 3) {
            ok = 1;
            vector<int> pos;
            for(int i=0;i<n;++i) if(Mx==a[i]) pos.push_back(i);
            cout << "YES" << endl;
            cout << pos[1] << " " << 1 << " " << n-pos[1]-1 << endl;
        }
        if(!ok) {
            for(auto p : mp) {
                if(p.second < 3) continue;
                int x = p.first;
                int l = first_greater_than_x(1, n, x, 1, n, 1),
                        r = last_greater_than_x(1, n, x, 1, n, 1);
                if(l == 1 || r == n) continue;
                if(posl[x]+1 >= l || posr[x]+1 <= r) continue;
                int qry;
                if((qry = query_min(l, r, 1, n, 1)) < x) continue;
                if(qry == x) {
                    cout << "YES\n";
                    cout << l-1 << " " << r-l+1 << " " << n-r << endl;
                    ok = 1;
                    break;
                }
                else if(a[l-2] == x && posl[x] < l-2) {
                    cout << "YES\n";
                    cout << l-2 << " " << r-l+2 << " " << n-r << endl;
                    ok = 1;
                    break;
                }
                else if(a[r] == x && posr[x] > r) {
                    cout << "YES\n";
                    cout << l-1 << " " << r-l+2 << " " << n-r-1 << endl;
                    ok = 1;
                    break;
                }
            }
        }
        if(!ok) cout << "NO\n";
    }
}