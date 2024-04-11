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
//typedef pair<int, int> pii;

inline int read() {
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
const int mod = 1e9 + 7;
typedef pair<ll, ll> pii;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    int t = read();
    while(t--) {
        int n = read(), p = read();
        priority_queue<pii> q;
        if(p == 1) {
            for(int i=0;i<n;++i) read();
            printf("%d\n", n&1);
            continue;
        }
        for(int i=0;i<n;++i) {
            int a = read();
            q.push({a,1});
        }

        ll ans = 0;
        int f = 0;
        while(q.size() > 1) {
            auto p1 = q.top(); q.pop();
            auto p2 = q.top(); q.pop();
            ll cur1 = p1.first, cnt1 = p1.second;
            ll cur2 = p2.first, cnt2 = p2.second;
            assert(cur1 >= cur2);
            while(cur1 > cur2) {
                --cur1;
                cnt1 = cnt1 * p;
                if(cnt1 > n) {
                    ans = fpow(p, cur1) * cnt1 % mod;
                    ans -= fpow(p, cur2) * cnt2 % mod;
                    while(!q.empty()) {
                        auto tmp = q.top(); q.pop();
                        ans -= fpow(p, tmp.first) * tmp.second % mod;
                    }
                    f = 1;
                    break;
                }
            }
            if(f) break;
            cnt1 -= cnt2;
            assert(cnt1 >= 0);
            if(cnt1) q.push({cur1, cnt1});
        }
        if(!q.empty()) ans = fpow(p, q.top().first) * q.top().second % mod;
        ans %= mod;
        if(ans < 0) ans += mod;
        printf("%lld\n", ans);
    }
}