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

ll fibs[40000],arr[40000],cnt[40000];

struct node{
    ll sz;
    ll sm0,sm1;
    node(ll a=0,ll b=0,ll c=0){ sz=a,sm0=b,sm1=c; }
};
typedef node nd;

ll md,n;
ll up(ll x1, ll x2, ll k){return !k?x1:(x1*fibs[k-1] + x2*fibs[k])%md;}

void upd(nd& n,nd l,nd r){
    ll sz = l.sz;
    n.sm0 = (l.sm0 + up(r.sm0,r.sm1,sz))%md;
    n.sm1 = (l.sm1 + up(r.sm0,r.sm1,sz+1))%md;
    n.sz = sz + r.sz;
}

node t[2*40000];
void modify(int p,node x){
    for(t[p+=n]=x;p>>=1;)upd(t[p],t[p<<1],t[p<<1|1]);
}

void add(int x){
    if(!cnt[x]++) modify(x,nd(1,0,arr[x]));
}
void rem(int x){
    if(!--cnt[x]) modify(x,nd(0,0,0));
}

int main(){
    int n,q;
    scanf("%d%I64d",&n,&md);
    ::n=1;
    while(::n<n)::n*=2;
    fibs[0]=0, fibs[1]=1;
    rep(i,2,35000)fibs[i]=(fibs[i-1]+fibs[i-2])%md;
    vi v(n);
    rep(i,0,n)scanf("%d",&v[i]);
    unordered_map<int,int> mq;
    vi w=v;
    sort(allof(w));
    rep(i,0,n)arr[i]=w[i],mq[w[i]]=i;
    cin>>q;
    typedef tuple<int,int,int> query;
    vector<query> que(q);
    rep(i,0,q){
       int l,r;
       scanf("%d%d",&l,&r);
       que[i] = query(l-1,r-1,i);
    }
    ll s = sqrt(n);
    sort(allof(que),
        [s](query& a,query& b)->bool{
            int al,ar,bl,br;
            tie(al,ar,ignore) = a;
            tie(bl,br,ignore) = b;
            if(al/s != bl/s) return al < bl;
            return (ar<br) ^ ((al/s)&1);
        });
    vi ans(q);
    int l=get<1>(que[0])+1,r=l-1;
    for(query q:que){
        int ql,qr,qi;
        tie(ql,qr,qi) = q;
        while(r<qr) add(mq[v[++r]]);
        while(l>ql) add(mq[v[--l]]);
        while(r>qr) rem(mq[v[r--]]);
        while(l<ql) rem(mq[v[l++]]);
        ans[qi] = t[1].sm1;
    }
    rep(i,0,q) printf("%d\n",ans[i]);
    return 0;
}