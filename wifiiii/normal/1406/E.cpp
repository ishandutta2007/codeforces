#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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

const int maxn = 100005;
int np[maxn], prime[maxn], mp[maxn], tot = 0;
int cnt[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (np[i]) continue;
        prime[++tot] = i;
        cnt[i]++;
        for (int j = 2 * i; j <= n; j += i) {
            if (!mp[j]) {
                mp[j] = i;
                cnt[i]++;
            }
            np[j] = 1;
        }
    }
    vector<int> ans;
    int all = n;
    int cur = 0;
    int b = 40;
    ll opt = 1;
//    int op = 0;
    while (1) {
        if (cur == tot) break;
        int last = cur;
        if(opt * prime[cur] > n) break;
        for (int i = 1; i <= b; ++i) {
            if (cur == tot) break;
            ++cur;
            cout << "B " << prime[cur] << endl;
            int tmp;
            cin >> tmp;
            all -= cnt[prime[cur]];
//            ++op;
        }
        cout << "A 1" << endl;
//        ++op;
        int res;
        cin >> res;
        if (all == res) continue;
        for (int i = 1; i <= b; ++i) {
            if (last == tot) break;
            ++last;
            cout << "A " << prime[last] << endl;
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                ans.push_back(prime[last]);
            }
        }
        while(last < tot) {
            ++last;
            cout << "B " << prime[last] << endl;
            int tmp;
            cin >> tmp;
            if (tmp != cnt[prime[last]]) {
                ans.push_back(prime[last]);
            }
        }
        break;
    }
//    cout << op+b << endl;
    if (ans.empty()) return cout << "C " << 1 << endl, 0;
    ll res = 1;
    for (int i : ans) {
        res *= i;
        for (ll j = 1ll * i * i; j <= n; j *= i) {
            cout << "A " << j << endl;
            int tmp;
            cin >> tmp;
            if (tmp == 0) break;
            res *= i;
        }
    }
    cout << "C " << res << endl;
}