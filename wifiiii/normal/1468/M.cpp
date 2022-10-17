#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

vector<int> a[200005];
vector<pair<int,int>> r[200005];
int cnt[200005];
inline int read() {
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main() {
    int t = read();
    while(t--) {
        int n = read();
        int sz = 0;
        for(int i=1;i<=n;++i) a[i].clear();
        vector<int> aa;
        for(int i=1;i<=n;++i) {
            int x = read();
            sz += x;
            while(x--) {
                int y = read();
                a[i].push_back(y);
                aa.push_back(y);
            }
        }
        sort(aa.begin(), aa.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        auto f = [&](int x) {
            return lower_bound(aa.begin(), aa.end(), x) - aa.begin() + 1;
        };
        for(int i=1;i<=n;++i) {
            for(int &j:a[i]) j=f(j);
            sort(all(a[i]));
        }
        int sq = pow(sz, 0.4), ok = 0;
        for(int i=1;i<=n;++i) {
            if(a[i].size() > sq) {
                for(int j:a[i]) cnt[j]++;
                for(int j=1;j<=n;++j) {
                    if(i==j) continue;
                    int cnt2=0;
                    for(int k:a[j]) cnt2+=cnt[k];
                    if(cnt2>1) {
                        printf("%d %d\n", i, j);
                        ok=1;
                        break;
                    }
                }
                for(int j:a[i]) cnt[j]--;
            } else {
                for(int j=0;j<a[i].size();++j) {
                    for(int k=j+1;k<a[i].size();++k) {
                        r[a[i][j]].push_back({a[i][k], i});
                    }
                }
            }
            if(ok) break;
        }
        if(!ok) {
            for(int i=1;i<=aa.size();++i) {
                sort(all(r[i]));
                for(int j=1;j<r[i].size();++j) {
                    if(r[i][j].first == r[i][j-1].first) {
                        ok = 1;
                        printf("%d %d\n", r[i][j].second, r[i][j-1].second);
                        break;
                    }
                }
                if(ok) break;
            }
        }
        for(int i=1;i<=aa.size();++i) r[i].clear();
        if(!ok) puts("-1");
    }
}