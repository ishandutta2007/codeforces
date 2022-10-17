#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

const int N=300005;
const ll nl=numeric_limits<ll>::min();

struct CH{
    vector<ll> x,y;
    ld intersect(ll x1,ll y1,ll x2,ll y2){
        return (y2-y1)*ld(1)/(x1-x2);
    }
    void insert(ll x1,ll y1){ //xx must be increasing in insert queries
        if(x.size() && x.back()==x1) //parallel
            x.pop_back(),y.pop_back();
        while(x.size()>1){
            ll x2=x[x.size()-1], x3=x[x.size()-2];
            ll y2=y[y.size()-1], y3=y[y.size()-2];
            if(intersect(x1,y1,x2,y2)>intersect(x2,y2,x3,y3)) break;
            x.pop_back();
            y.pop_back();
        }
        x.pb(x1),y.pb(y1);
    }
    ll query(ll t){ //find max of x*t+y
        if(x.empty()) return nl;
        int a=-1,b=x.size()-1;
        while(a+1<b){
            int m = (a+b)/2;
            if(m!=-1 && t<intersect(x[m],y[m],x[m+1],y[m+1])) 
                b = m;
            else
                a = m;
        }
        return x[b]*t+y[b];
    }
}ch[2*N];

int n;

void update(int l,int r,ll x,ll y){
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)ch[l++].insert(x,y);
        if(r&1)ch[--r].insert(x,y);
    }
}
ll query(int p,ll t){
    ll res=nl;
    for(p+=n;p>0;p>>=1)
        res=max(res,ch[p].query(t));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<ll> x(n),y(n),d(n,n);
    vi t1,t3;
    rep(i,0,n){
        int t;
        cin>>t;
        if(t==1)
            cin>>x[i]>>y[i], t1.pb(i);
        if(t==2)
            cin>>x[i], d[x[i]-1]=i;
        if(t==3)
            cin>>x[i], t3.pb(i);
    }
    sort(allof(t1),[&](int a,int b){return mp(x[a],y[a])<mp(x[b],y[b]);});
    for(int t:t1) update(t,d[t],x[t],y[t]);
    for(int t:t3){
        ll k = query(t,x[t]);
        if(k==nl) cout<<"EMPTY SET\n";
        else cout<<k<<"\n";
    }
    return 0;
}