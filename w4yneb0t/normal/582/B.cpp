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
in p2(in a){
  return (1LL<<a);
}
const in inf=in(1e9)+9;
struct fp{
  in a;
  fp(in aa=0){
    a=aa;
    a=min(a,inf);
    a=max(a,-inf);
  }
  fp operator*(const fp cp)const{
    return fp(a+cp.a);
  }
  fp operator+(const fp cp)const{
    return fp(max(a,cp.a));
  }
  fp& operator*=(const fp cp){
    return (*this)=(*this)*cp;
  }
  fp& operator+=(const fp cp){
    return (*this)=(*this)+cp;
  }
};
template<typename T> struct mat{
  vector<vector<T> > a;
  in n,m;
  T ab(T a){
    return a>0?a:-a;
  }
  void ini(in pn, in pm){
    a.clear();
    n=pn;
    m=pm;
    a.resize(n,vector<T>(m,-inf));
  }
  mat<T> operator*(const mat<T>& cp)const{
    assert(m==cp.n);
    mat r;
    r.ini(n,cp.m);
    forn(i,n){
      forn(j,cp.m){
	forn(k,m){
	  r.a[i][j]+=a[i][k]*cp.a[k][j];
	}
      }
    }
    return r;
  }
};
template<typename T> mat<T> pwm(mat<T> a, in b){
  mat<T> r;
  assert(a.n==a.m);
  r.ini(a.n,a.m);
  forn(i,a.n)
    r.a[i][i]=0;
  for(in i=62;i>=0;--i){
    r=r*r;
    if(b&p2(i))
      r=r*a;
  }
  return r;
}
typedef mat<fp> mt;
VI mar;
mt mmat;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,t;
  cin>>n>>t;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  mar.PB(0);
  ++n;
  mmat.ini(n,n);
  forn(i,n){
    forn(j,n){
      if(mar[j]<=mar[i])
	mmat.a[i][j]=1;
    }
    forn(pv,i){
      if(mar[pv]>mar[i])
	continue;
      forn(j,n){
	mmat.a[i][j]=max(mmat.a[i][j].a,mmat.a[pv][j].a+1);
      }
    }
  }
  mmat=pwm(mmat,t);
  mt cm;
  cm.ini(n,1);
  cm.a[n-1][0]=0;
  cm=mmat*cm;
  in mx=0;
  forn(i,n)
    mx=max(mx,cm.a[i][0].a);
  cout<<mx<<endl;
  return 0;
}