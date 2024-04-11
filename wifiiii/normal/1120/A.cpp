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

const int maxn = 500005; // todo
int a[maxn], b[maxn];
vector<int> pos[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    for(int i=1;i<=m;++i) cin >> a[i];
    for(int i=1;i<=s;++i) {
        int x;
        cin >> x;
        b[x]++;
    }
    vector<pair<int,int>> vp;
    for(int i=1;i<maxn;++i) {
        if(b[i]) vp.push_back({i, b[i]});
    }
    for(int i=1;i<=m;++i) pos[a[i]].push_back(i);
    int cut = m - k * n;
    for(int i=1;i<=m;i+=k) {
        int cur = i, ok = 1;
        vector<int> v;
        for(auto &p : vp) {
            int tmp = i;
            for(int j=0;j<p.second;++j) {
                int p2 = lower_bound(all(pos[p.first]),tmp)-pos[p.first].begin();
                if(p2 == pos[p.first].size()) {
                    ok = 0;
                    break;
                }
                v.push_back(pos[p.first][p2]);
                tmp = pos[p.first][p2] + 1;
            }
            cur = max(cur, tmp);
            if(!ok) break;
        }
        if(!ok) break;
        if(cur - i - k <= cut) {
            sort(v.begin(), v.end());
            cout << max(0, cur - i - k) << endl;
            int need = max(0, cur - i - k);
            int p = 0;
            for(int j=i;j<cur;++j) {
                if(!need) break;
                if(p < v.size() && v[p] == j) {
                    ++p;
                    continue;
                }
                cout << j << ' ';
                --need;
            }
            if(cur - i - k) cout << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}