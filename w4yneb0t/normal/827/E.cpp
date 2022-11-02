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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const double PI=3.14159265358979323;
const in mxcis=1<<20; // sum of sizes of arrays you're convoluting
struct comp{
  double re,im;
  comp(double a=0, double b=0){
    re=a;
    im=b;
  }
  comp conj()const{
    return comp(re,-im);
  }
  comp operator+(const comp cp)const{
    return comp(re+cp.re,im+cp.im);
  }
  comp operator-(const comp cp)const{
    return comp(re-cp.re,im-cp.im);
  }
  comp operator*(const comp cp)const{
    return comp(re*cp.re-im*cp.im,re*cp.im+im*cp.re);
  }
  comp operator*(const double cp)const{
    return comp(re*cp,im*cp);
  }
  comp operator/(const double cp)const{
    return comp(re/cp,im/cp);
  }
  comp& operator/=(const double cp){
    re/=cp;
    im/=cp;
    return *this;
  }
  double sqn()const{
    return ((*this)*(conj())).re;
  }
  comp operator/(const comp cp)const{
    return (*this)*cp.conj()/cp.sqn();
  }
  comp& operator+=(const comp cp){
    return (*this)=(*this)+cp;
  }
  comp& operator-=(const comp cp){
    return (*this)=(*this)-cp;
  }
  comp& operator*=(const comp cp){
    return (*this)=(*this)*cp;
  }
};
const comp iot(0,1);
const comp one(1,0);
vector<comp> cissv;
comp cis(double a){
  return comp(cos(a),sin(a));
}
vector<comp> ret(mxcis);
void pm(vector<comp>& v, in& n){
  forn(i,n/2){
    ret[i]=v[2*i];
    ret[i+n/2]=v[2*i+1];
  }
  forn(i,n)
    v[i]=ret[i];
}
const in brlm=10;
vector<comp> tv(brlm);
const in MXDPT=30;
vector<comp> v1[MXDPT];
void fft(vector<comp>& v,in infc,in dpt,bool ntdv=1){
  in n=sz(v);
  if(n==1)
    return;
  in divc=mxcis/n;
  if(n<=brlm){
    forn(i,n){
      tv[i]=v[i];
      v[i]=0;
    }
    if(infc==1){
      forn(i,n){
	forn(j,n){
	  v[i]+=tv[j]*cissv[mxcis-divc*i*j%mxcis];
	}
      }
    }
    else{
      forn(i,n){
	forn(j,n){
	  v[i]+=tv[j]*cissv[divc*i*j%mxcis];
	}
      }
    }
    if(ntdv){
      double sq=sqrt(n);
      forn(i,n)
	v[i]/=sq;
    }
    return;
  }
  assert(n%2==0);
  pm(v,n);
  assert(dpt<MXDPT);
  v1[dpt].resize(n/2);
  forn(i,n/2)
    v1[dpt][i]=v[i];
  fft(v1[dpt],infc,dpt+1,0);
  forn(i,n/2){
    swap(v[i+n/2],v1[dpt][i]);
    v[i]=v[i+n/2];
  }
  fft(v1[dpt],infc,dpt+1,0);
  comp tm;
  if(infc==1){
    forn(i,n/2){
      tm=v1[dpt][i]*cissv[mxcis-divc*i];
      v[i]+=tm;
      v[i+n/2]-=tm;
    }
  }
  else{
    forn(i,n/2){
      tm=v1[dpt][i]*cissv[divc*i];
      v[i]+=tm;
      v[i+n/2]-=tm;
    }
  }
  if(ntdv){
    double sq=sqrt(n);
    forn(i,n)
      v[i]/=sq;
  }
}
in rnd(double a){
  if(a>0)
    return a+0.5;
  return a-0.5;
}
VI conv(VI a, VI b){
  if(sz(cissv)==0){
    cissv.resize(mxcis+1);
    forv(i,cissv){
      cissv[i]=cis(i*2*PI/double(mxcis));
    }
  }
  in n=sz(a);
  in m=sz(b);
  if(n+m<=1000){
    VI ans(n+m-1);
    in lm,um;
    in c;
    forv(i,ans){
      lm=min(i+1,n);
      um=max(i-m+1,0);
      c=0;
      for(in x=um;x<lm;++x){
	c+=a[x]*b[i-x];
      }
      ans[i]=c;
    }
    return ans;
  }
  in np2=1;
  while(np2<n+m)
    np2*=2;
  double sq=sqrt(np2);
  vector<comp> c1,c2;
  c1.resize(np2);
  c2.resize(np2);
  forn(i,n)
    c1[i]=comp(a[n-1-i],0);
  for(in i=n-1;i<n+m-1;i++)
    c2[i]=comp(b[i-n+1],0);
  fft(c1,1,0);
  fft(c2,1,0);
  forn(i,np2)
    c2[i]*=c1[i].conj()*sq;
  fft(c2,-1,0);
  VI rt(np2);
  forn(i,np2)
    rt[i]=rnd(c2[i].re);
  for(in i=n+m-1;i<np2;++i)
    assert(rt[i]==0);
  assert(rt[n-1+m-1]==a[n-1]*b[m-1]);
  assert(rt[0]==a[0]*b[0]);
  rt.resize(n+m-1);
  return rt;
}
in ab(in a){
  return a<0?-a:a;
}
string s;
VI posv,posk,con;
VI ans;
VI bad;
void dot(){
  in n;
  cin>>n;
  cin>>s;
  posv.resize(n);
  posk.resize(n);
  forn(i,n){
    posv[i]=(s[i]=='V');
    posk[i]=(s[n-1-i]=='K');
  }
  con=conv(posv,posk);
  bad.resize(n);
  forn(i,n)
    bad[i]=0;
  forv(i,con){
    if(con[i])
      bad[ab(n-1-i)]=1;
  }
  ans.clear();
  for(in i=1;i<=n;++i){
    bool ok=1;
    for(in j=i;j<n;j+=i){
      if(bad[j])
	ok=0;
    }
    if(ok)
      ans.PB(i);
  }
  cout<<sz(ans)<<"\n";
  forv(i,ans)
    cout<<ans[i]<<" ";
  cout<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in t;
  cin>>t;
  forn(z,t){
    dot();
  }
  return 0;
}