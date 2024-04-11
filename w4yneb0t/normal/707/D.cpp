#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in m;
const in fm=62;
in p2(in a){
  return 1LL<<a;
}
struct row{
  VI msks;
  row(){
    msks.resize((m+fm-1)/fm);
  }
  row(const row& a){
    msks=a.msks;
  }
  row* op(in typ, in a){
    row* r=new row(*this);
    if(typ==1)
      r->msks[a/fm]|=p2(a%fm);
    if(typ==2)
      r->msks[a/fm]&=~p2(a%fm);
    if(typ==3){
      forn(i,sz(msks)-1)
	r->msks[i]^=p2(fm)-1;
      r->msks.back()^=p2(m-fm*(sz(msks)-1))-1;
    }
    return r;
  }
  in fsm(){
    in r=0;
    forv(i,msks)
      r+=__builtin_popcountll(msks[i]);
    return r;
  }
};
struct full{
  in ls,rs;
  full* l,*r;
  row* mr;
  in sm;
  full(){
  }
  full(full* a, full* b){
    l=a;
    r=b;
    sm=a->sm+b->sm;
    ls=a->ls;
    rs=b->rs;
    assert(a->rs+1==b->ls);
    mr=NULL;
  }
};
full* upd(full* o, in typ, in a, in b){
  if(a<o->ls || a>o->rs)
    return o;
  if(o->ls!=o->rs)
    return new full(upd(o->l,typ,a,b),upd(o->r,typ,a,b));
  full* r=new full();
  *r=*o;
  r->mr=r->mr->op(typ,b);
  r->sm=r->mr->fsm();
  return r;
}
full* ini(in a, in b){
  full* r=new full();
  r->ls=a;
  r->rs=b;
  r->sm=0;
  if(a==b){
    r->l=r->r=NULL;
    r->mr=new row();
    return r;
  }
  in m=(a+b)/2;
  r->l=ini(a,m);
  r->r=ini(m+1,b);
  r->mr=NULL;
  return r;
}
vector<full*> aft;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,q;
  cin>>n>>m>>q;
  aft.PB(ini(0,n-1));
  in typ,a,b;
  b=0;
  full* cr=aft[0];
  for(in z=1;z<=q;++z){
    cin>>typ>>a;
    if(typ<=2)
      cin>>b;
    if(typ<=3)
      aft.PB(upd(cr,typ,a-1,b-1));
    else
      aft.PB(aft[a]);
    cr=aft[z];
    cout<<cr->sm<<"\n";
  }
  return 0;
}