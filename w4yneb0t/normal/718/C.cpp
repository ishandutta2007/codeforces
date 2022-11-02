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
const in mdl=1000000007LL;
in pmod=mdl;
in p2(in a){
  return (1LL<<a);
}
struct fp{
  in a;
  fp(in aa=0){
    a=aa;
    if(a<0 || a>=pmod)
      a%=pmod;
    if(a<0)
      a+=pmod;
  }
  fp operator*(const fp cp)const{
    return fp(a*cp.a);
  }
  fp operator+(const fp cp)const{
    return fp((a+cp.a)>pmod?a+cp.a-pmod:a+cp.a);
  }
  fp& operator*=(const fp cp){
    return (*this)=(*this)*cp;
  }
  fp& operator+=(const fp cp){
    return (*this)=(*this)+cp;
  }
};
struct vt{
  fp a[2];
  void ini(){
    forn(i,2){
      a[i]=0;
    }
  }
  vt operator+(const vt& cp)const{
    vt r;
    r.ini();
    forn(i,2){
      r.a[i]=a[i]+cp.a[i];
    }
    return r;
  }
};
struct mt{
  fp a[2][2];
  void ini(){
    forn(i,2){
      forn(j,2)
	a[i][j]=0;
    }
  }
  mt operator*(const mt& cp)const{
    mt r;
    r.ini();
    forn(i,2){
      forn(j,2){
	forn(k,2)
	  r.a[i][j]+=a[i][k]*cp.a[k][j];
      }
    }
    return r;
  }
  vt operator*(const vt& cp)const{
    vt r;
    r.ini();
    forn(i,2){
      forn(j,2){
	r.a[i]+=a[i][j]*cp.a[j];
      }
    }
    return r;
  }
  mt operator+(const mt& cp)const{
    mt r;
    r.ini();
    forn(i,2){
      forn(j,2)
	r.a[i][j]=a[i][j]+cp.a[i][j];
    }
    return r;
  }
};
mt pwm(mt a, in b){
  mt r;
  r.ini();
  forn(i,2)
    r.a[i][i]=1;
  for(in i=32;i>=0;--i){
    r=r*r;
    if(b&(1LL<<i))
      r=r*a;
  }
  return r;
}
mt ad1;
VI iscl;
vector<mt> ntp;
vector<vt> vl;
VI l,r;
vt t0;
mt nt;
void ad(in tl, in tr, mt x, in id){
  if(tr<l[id] || tl>r[id])
    return;
  if(tl<=l[id] && tr>=r[id]){
    vl[id]=x*vl[id];
    ntp[id]=ntp[id]*x;
    iscl[id]=0;
    return;
  }
  ad(tl,tr,x,2*id);
  ad(tl,tr,x,2*id+1);
  if(!iscl[id]){
    ad(l[id],r[id],ntp[id],2*id);
    ad(l[id],r[id],ntp[id],2*id+1);
    ntp[id]=nt;
    iscl[id]=1;
  }
  vl[id]=vl[2*id]+vl[2*id+1];
}
vt sm(in tl, in tr, in id){
  if(tr<l[id] || tl>r[id])
    return t0;
  if(tl<=l[id] && tr>=r[id])
    return vl[id];
  if(!iscl[id]){
    ad(l[id],r[id],ntp[id],2*id);
    ad(l[id],r[id],ntp[id],2*id+1);
    ntp[id]=nt;
    iscl[id]=1;
  }
  return sm(tl,tr,2*id)+sm(tl,tr,2*id+1);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  ad1.ini();
  ad1.a[0][0]=ad1.a[0][1]=ad1.a[1][0]=1;
  vt bs;
  bs.ini();
  t0=bs;
  bs.a[1]=1;
  mt id=pwm(ad1,0);
  nt=id;
  in pn=n;
  while(pn&(pn-1))
    ++pn;
  ntp.resize(2*pn,id);
  vl.resize(2*pn,bs);
  l.resize(2*pn);
  r.resize(2*pn);
  iscl.resize(2*pn,1);
  in tp;
  forn(i,n){
    cin>>tp;
    vl[pn+i]=pwm(ad1,tp)*bs;
  }
  forn(i,pn)
    l[i+pn]=r[i+pn]=i;
  for(in i=pn-1;i>=0;--i){
    l[i]=l[2*i];
    r[i]=r[2*i+1];
    vl[i]=vl[2*i]+vl[2*i+1];
  }
  in tl,tr,tx;
  forn(z,m){
    cin>>tp>>tl>>tr;
    --tl;
    --tr;
    if(tp==1){
      cin>>tx;
      ad(tl,tr,pwm(ad1,tx),1);
    }
    else{
      cout<<sm(tl,tr,1).a[0].a<<"\n";
    }
  }
  return 0;
}