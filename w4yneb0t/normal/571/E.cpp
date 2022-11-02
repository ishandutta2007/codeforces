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
void ext(in a){
  cout<<a<<endl;
  exit(0);
}
void fil(){
  ext(-1);
}
in ab(in a){
  return a<0?-a:a;
}
in gcd(in a, in b){
  if(b==0)
    return ab(a);
  return gcd(b,a%b);
}
void adr(in& rs1, in& rp1, in s2, in p2){
  in s1=rs1;
  in p1=rp1;
  in g=gcd(p1,p2);
  if((s2-s1)%g)
    fil();
  in np=p1/g*p2;
  //(s2+k*p2-s1)%p1==0
  swap(p1,p2);
  swap(s1,s2);
  if(s2<s1){
    s2+=p2*((s1-s2+p2-1)/p2);
  }
  in gm=(s1-s2)%p1;
  if(gm<0)
    gm+=p1;
  in k;
  for(k=0;k<p1;k++){
    if(p2%p1*k%p1==gm){
      break;
    }
  }
  assert(k<p1);
  rs1=s2+k*p2;
  rp1=np;
}
in pw(in a, in b){
  in r=1;
  for(in i=62;i>=0;i--){
    r=r*r%mdl;
    if(b&(1LL<<i))
      r=r*a%mdl;
  }
  return r;
}
void fl(in a, map<in,in>& tp){
  for(in i=2;i*i<=a;i++){
    if(a%i==0){
      in cc=0;
      while(a%i==0){
	a/=i;
	cc++;
      }
      tp[i]=cc;
    }
  }
  if(a!=1)
    tp[a]=1;
}
in n;
VI a,b;
vector<map<in,in> > apw,bpw;
void rcb(in id, map<in,in> npw){
  in crc=bpw[id].begin()->first;
  in crp=bpw[id].begin()->second;
  assert(crp);
  in st=apw[id][crc];
  in gl=npw[crc];
  if(gl<st)
    fil();
  if((gl-st)%crp)
    fil();
  in cf=(gl-st)/crp;
  fors(i,bpw[id])
    apw[id][i->first];
  fors(i,npw)
    apw[id][i->first];
  fors(i,apw[id])
    if(i->second+cf*bpw[id][i->first]!=npw[i->first])
      fil();
}
void mksol(in id, in cb){
  map<in,in> npw;
  fors(i,apw[id])
    npw[i->first]+=i->second;
  if(cb!=0){
    fors(i,bpw[id])
      npw[i->first]+=cb*i->second;
  }
  forn(j,n){
    rcb(j,npw);
  }
  in r=1;
  fors(i,npw){
    r*=pw(i->first,i->second);
    r%=mdl;
  }
  ext(r);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  a.resize(n);
  b.resize(n);
  forn(i,n)
    cin>>a[i]>>b[i];
  if(n==1)
    ext(a[0]);
  forn(i,n){
    if(b[i]==1){
      forn(j,n){
	in cc=a[i];
	if(cc%a[j])
	  fil();
	cc/=a[j];
	if(b[j]==1 && cc!=1)
	  fil();
	while(cc!=1){
	  if(cc%b[j])
	    fil();
	  cc/=b[j];
	}
      }
      ext(a[i]);
    }
  }
  apw.resize(n);
  bpw.resize(n);
  forn(i,n){
    fl(a[i],apw[i]);
    fl(b[i],bpw[i]);
  }
  forn(i,n){
    forn(j,n){
      if(j==i)continue;
      in fs=-1,sc,ca;
      fors(it,bpw[i]){
	if(!bpw[j].count(it->first)){
	  in iapw=0;
	  if(apw[i].count(it->first))
	    iapw=apw[i][it->first];
	  in japw=0;
	  if(apw[j].count(it->first))
	    japw=apw[j][it->first];
	  in ibpw=it->second;
	  if(japw<iapw)
	    fil();
	  if((japw-iapw)%ibpw)
	    fil();
	  mksol(i,(japw-iapw)/ibpw);
	}
	in cfs=it->second;
	in csc=bpw[j][it->first];
	in cca=0;
	if(apw[i].count(it->first))
	  cca=apw[i][it->first];
	if(apw[j].count(it->first))
	  cca-=apw[j][it->first];
	in g=gcd(cfs,csc);
	g=gcd(g,cca);
	cfs/=g;
	csc/=g;
	cca/=g;
	cca=-cca;
	if(fs==-1){
	  fs=cfs;
	  sc=csc;
	  ca=cca;
	}
	else{
	  if(fs!=cfs || sc!=csc || ca!=cca){
	    //fs*x1-sc*x2=ca
	    //cfs*x1-csc*x2=cca
	    //x1=(ca+sc*x2)/fs=(cca+csc*x2)/cfs
	    // x2*(sc*cfs-csc*fs)=cca*fs-ca*cfs
	    in upr=cca*fs-ca*cfs;
	    in lwr=sc*cfs-csc*fs;
	    in x2=0;
	    if(upr!=0){
	      if(lwr==0)
		fil();
	      if(upr%lwr)
		fil();
	      x2=upr/lwr;
	    }
	    upr=ca+sc*x2;
	    lwr=fs;
	    in x1=0;
	    if(upr!=0){
	      if(lwr==0)
		fil();
	      if(upr%lwr)
		fil();
	      x1=upr/lwr;
	    }
	    mksol(i,x1);
	  }
	}
      }
    }
  }
  in fpw=bpw[0].begin()->first;
  in fsol=apw[0][fpw];
  in per=bpw[0][fpw];
  for(in i=1;i<n;i++){
    adr(fsol,per,apw[i][fpw],bpw[i][fpw]);
  }
  mksol(0,(fsol-apw[0][fpw])/bpw[0][fpw]);
  return 0;
}