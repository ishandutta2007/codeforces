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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    ll s=0;
    cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i],s+=a[i];
    cin>>m;
    vi b(m);
    rep(i,0,m)cin>>b[i],s-=b[i];
    typedef tuple<ll,ll,ll,ll,ll> save;
    save best(abs(s),-1,-1,-1,-1);
    
    {
        vi aa(n),bb(m);
        rep(i,0,n)aa[i]=i;
        rep(i,0,m)bb[i]=i;
        sort(allof(aa),[&](int x,int y){return a[x]<a[y];});
        sort(allof(bb),[&](int x,int y){return b[x]<b[y];});
        int ia=0,ib=0;
        while(ia<n && ib<m){
            ll tmp=s-2*(a[aa[ia]]-b[bb[ib]]);
            best=min(best,make_tuple(abs(tmp),aa[ia],bb[ib],-1LL,-1LL));
            if(tmp>0) ++ia;
            else ++ib;
        }
    }

    {
        vector<pii> aaa,bbb;
        rep(i,0,n)rep(j,i+1,n)aaa.pb(mp(i,j));
        rep(i,0,m)rep(j,i+1,m)bbb.pb(mp(i,j));
        sort(allof(aaa),[&](pii x, pii y){return a[x.X]+a[x.Y]<a[y.X]+a[y.Y];});
        sort(allof(bbb),[&](pii x, pii y){return b[x.X]+b[x.Y]<b[y.X]+b[y.Y];});
        int ia=0,ib=0;
        while(ia<aaa.size() && ib<bbb.size()){
            ll tmp=s-2*(a[aaa[ia].X]+a[aaa[ia].Y]-b[bbb[ib].X]-b[bbb[ib].Y]);
            best=min(best,make_tuple(abs(tmp),aaa[ia].X,bbb[ib].X,aaa[ia].Y,bbb[ib].Y));
            if(tmp>0) ++ia;
            else ++ib;
        }
    }
    ll v,a1,b1,a2,b2;
    tie(v,a1,b1,a2,b2)=best;
    cout<<v<<endl;
    if(a1==-1){
        cout<<0<<endl;
        return 0;
    }
    if(a2==-1){
        cout<<1<<endl<<a1+1<<" "<<b1+1<<endl;
        return 0;
    }
    cout<<2<<endl<<a1+1<<" "<<b1+1<<endl<<a2+1<<" "<<b2+1<<endl;;


    return 0;
}