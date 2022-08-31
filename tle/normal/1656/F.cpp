#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ 344444
int T,n;
ll a[SZ];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pair<ll,pii>> q;
int ff[SZ];
int gf(int x) {
    if(!ff[x]) return x;
    return ff[x]=gf(ff[x]);
}
void merge(int x,int y) {
    int fx=gf(x),fy=gf(y);
    if(fx==fy) return;
    ff[fx]=fy;
}
ll qz[SZ];
pair<ll,ll> qs[SZ]; int qn;
void sol() {
    scanf("%d",&n); qn=0;
    for(int i=1;i<=n;++i) scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) qz[i]=qz[i-1]+a[i];
    for(int i=1;i<n;++i) {
        //1 -- i+1~n
        //2~i -- n
        // ll c0=0,c1=0;
        // for(int j=i+1;j<=n;++j)
        //     c0+=a[1]*a[j],c1+=a[1]+a[j];
        // for(int j=2;j<=i;++j)
        //     c0+=a[j]*a[n],c1+=a[j]+a[n];
       ll c0=(qz[n]-qz[i])*a[1]+a[n]*(qz[i]-qz[1]);
       ll c1=(qz[n]-qz[i])+(n-i)*a[1]+(qz[i]-qz[1])+(i-1)*a[n];
        qs[++qn]=make_pair(c1,c0);
    }
    sort(qs+1,qs+1+qn);
    // for(int i=1;i<=qn;++i)
    //     cout<<qs[i].first<<','<<qs[i].second<<" ";cout<<"\n";
    if(qs[1].first>0||qs[qn].first<0) {
        puts("INF");
        return;
    }
    vector<pair<ll,ll>> es;
    auto jx=[&](pair<ll,ll> a,pair<ll,ll> b) {
        return (long double)(a.second-b.second)/(a.first-b.first);
    };
    for(int i=1;i<=qn;++i) {
        if(es.size()&&es.back().first==qs[i].first) continue;
        while(es.size()>=2&&jx(es[es.size()-2],es[es.size()-1])>=jx(es[es.size()-1],qs[i]))
            es.pop_back();
        es.push_back(qs[i]);
    }
    ll ans=-8e18;
    for(int i=0;i<es.size();++i) if(!es[i].first) ans=max(ans,es[i].second);
    for(int i=1;i<es.size();++i) {
        ll x1=es[i].first,x2=es[i].second;
        ll y1=es[i-1].first,y2=es[i-1].second;
        //y1*t+y2=x1*t+x2
        //t=(x2-y2)/(y1-x1)
        ll ca=(x2-y2)*(__int128)y1/(y1-x1)+y2;
        ans=max(ans,ca);
    }
    printf("%lld\n",ans);
}
int main() {
    scanf("%d",&T);
    while(T--) sol();
}