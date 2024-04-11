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
struct unifnd{
  VI ht,pr;
  in fnd(in a){
    in ta=a;
    while(a!=pr[a])a=pr[a];
    in tt=ta;
    while(ta!=a){
      tt=pr[ta];
      pr[ta]=a;
      ta=tt;
    }
    return a;
  }
  void uni(in a, in b){
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b]<ht[a])swap(a,b);
    pr[a]=b;
    ht[b]+=(ht[a]==ht[b]);
  }
  void ini(in n){
    ht.resize(n);
    pr.resize(n);
    forn(i,n){
      ht[i]=0;
      pr[i]=i;
    }
  }
};
set<in> lks;
unifnd tf;
void mrk(in x, in y){
  set<in>::iterator it=lks.lower_bound(x);
  set<in>::iterator it2;
  while(it!=lks.end() && *it<y){
    it2=it;
    ++it;
    tf.uni(*it2,*it2+1);
    lks.erase(it2);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,q;
  cin>>n>>q;
  forn(i,n+4)
    lks.insert(i);
  tf.ini(n+1);
  in typ,ta,tb;
  forn(zz,q){
    cin>>typ>>ta>>tb;
    if(typ==1)
      tf.uni(ta,tb);
    if(typ==2)
      mrk(ta,tb);
    if(typ==3)
      cout<<(tf.fnd(ta)==tf.fnd(tb)?"YES":"NO")<<"\n";
  }
  return 0;
}