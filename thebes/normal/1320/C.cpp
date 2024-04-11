#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5;
ll st[9*MN], lz[9*MN], ans=-1LL<<60;
int n, m, p, i; pll a[MN], b[MN]; struct hm{ll x, y, z;}c[MN],event[2*MN];
map<int,int> mp; 

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i] += lz[i];
        if(s!=e){
            lz[2*i] += lz[i];
            lz[2*i+1] += lz[i];
        }
        lz[i] = 0;
    }
}

void upd(int i,int s,int e,int ss,int se,ll val){
    if(ss>se) return;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i] = val;
        upd_lz(i,s,e);
    }
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i]=max(st[2*i],st[2*i+1]);
    }
}

ll qu(int i,int s,int e,int ss,int se){
    if(ss>se) return -1LL<<60;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return min(qu(2*i,s,(s+e)/2,ss,se),qu(2*i+1,(s+e)/2+1,e,ss,se));
}

int main(){
    for(scanf("%d%d%d",&n,&m,&p),i=1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
        mp[a[i].second]=0;
        event[i]={a[i].first,i,0};
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&b[i].first,&b[i].second);
        mp[b[i].first]=0;
    }
    for(i=1;i<=p;i++){
        scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
        mp[c[i].y+1]=0;
        event[i+n]={c[i].x,n+i,1};
    }
    sort(b+1,b+m+1,[](pll i,pll j){return i.first==j.first?i.second<j.second:i.first<j.first;});
    b[++m]={1<<30,1LL<<60};
    mp[b[m].first]=0;
    i = 0;
    for(auto it = mp.begin();it!=mp.end();it++) it->second=++i;
    int pre=0;
    int tot = mp.size();
    for(i=1;i<=m;i++){
        upd(1,1,tot,pre+1,mp[b[i].first],-b[i].second);
        pre = mp[b[i].first];
    }
    sort(event+1,event+n+p+1,[](hm i,hm j){return i.x==j.x?i.z<j.z:i.x<j.x;});
    for(i=1;i<=n+p;i++){
        if(event[i].z){
            upd(1,1,tot,mp[c[event[i].y-n].y+1],tot,c[event[i].y-n].z);
        }
        else{
            ans=max(ans,st[1]-a[event[i].y].second);
        }
    }
    printf("%lld\n",ans);
    return 0;
}