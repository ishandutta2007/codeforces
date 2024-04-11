#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 1e6+5;
int prime[maxn],np[maxn],minp[maxn],tot=0;
void init(int n) {
   np[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot] = i, minp[i] = i;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           np[i*prime[j]] = 1;
           minp[i*prime[j]] = prime[j];
           if(i%prime[j]==0) break;
       }
   }
}
int a[maxn];

inline ll read() {
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main() {
    init(maxn - 1);
    int t = read();
    while(t--) {
        int n = read();
        map<vector<int>, int> mp;
        for(int i=1;i<=n;++i) {
            int x = read();
            vector<int> v;
            while(x > 1) {
                int tmp = minp[x], cnt = 0;
                while(x % tmp == 0) {
                    x /= tmp;
                    ++cnt;
                }
                if(cnt & 1) v.push_back(tmp);
            }
            mp[v]++;
        }
        vector<int> ans(2);
        int mx = 0, s = 0;
        for(auto p : mp) {
            mx = max(mx, p.second);
            if(p.first.empty() || p.second % 2 == 0) {
                s += p.second;
            }
        }
        ans[0] = mx;
        ans[1] = max(s, mx);
        int q = read();
        while(q--) {
            ll x = read();
            x = min(x, 1ll);
            printf("%d\n", ans[x]);
        }
    }
}