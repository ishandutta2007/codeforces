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
typedef pair<int,int> pii;

int w[1<<12],a[13],cnt[1<<12];
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
inline int read2()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*2+c-'0',c=getchar();
    return x*f;
}
struct query {
    int y, id;
    bool operator < (const query & q) const {
        return y < q.y || (y == q.y && id < q.id);
    }
};
vector<query> qs[1<<12];
ll anss[500005];
int main() {
    int n=read(),m=read(),q=read();
    for(int i=1;i<=n;++i) a[i]=read();
    reverse(al(a));
    int tot=0;
    for(int i=1;i<=n;++i) tot+=a[i];
    for(int i=0;i<1<<n;++i) {
        w[i]=tot;
        for(int j=0;j<n;++j) if(i>>j&1) w[i]-=a[j+1];
    }
    for(int i=1;i<=m;++i) {
        int x=read2();
        cnt[x]++;
    }
    for(int i=1;i<=q;++i) {
        int x=read2();
        int y=read();
        qs[x].push_back({y, i});
    }
    for(int i=0;i<1<<12;++i) {
        if(!qs[i].size()) continue;
        sort(all(qs[i]));
        vector<pair<int,int>> tmp;
        for(int j=0;j<1<<n;++j) {
            if(cnt[j]) tmp.push_back({w[i^j],cnt[j]});
        }
        sort(all(tmp));
        int cur = 0;
        ll s = 0;
        for(auto &qry : qs[i]) {
            while(cur < tmp.size() && tmp[cur].first <= qry.y) {
                s += tmp[cur].second;
                ++cur;
            }
            anss[qry.id] = s;
        }
    }
    for(int i=1;i<=q;++i) printf("%lld\n", anss[i]);
}