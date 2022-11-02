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
struct nod{
  in mcst[4][4];
  nod(){
    forn(i,4){
      forn(j,4)
	mcst[i][j]=0;
    }
  }
  nod(char c){
    forn(i,4){
      forn(j,4)
	mcst[i][j]=0;
    }
    in bid=-1;
    if(c=='2')
      bid=0;
    if(c=='0')
      bid=1;
    if(c=='1')
      bid=2;
    if(c=='6')
      bid=3;
    if(bid==-1)
      return;
    mcst[bid][bid]=1;
  }
  nod& operator+=(const nod cp){
    in tc;
    for(in l=3;l>=0;--l){
      for(in i=0;i+l<4;++i){
	tc=1e8;
	for(in j=i;j<=i+l;++j)
	  tc=min(tc,mcst[i][j]+cp.mcst[j][i+l]);
	mcst[i][i+l]=tc;
      }
    }
    return (*this);
  }
};
in mx;
VI l,r;
vector<nod> tr;
string mar;
void qr(in a, in b, in id, nod& rs){
  if(b<l[id] || a>r[id])
    return;
  if(a<=l[id] && b>=r[id]){
    rs+=tr[id];
    return;
  }
  qr(a,b,2*id,rs);
  qr(a,b,2*id+1,rs);
  return;
}
nod tnd;
nod rqr(in a, in b){
  forn(i,4){
    forn(j,4)
      tnd.mcst[i][j]=0;
  }
  qr(a,b,1,tnd);
  return tnd;
}
void build(){
  in mx=sz(mar);
  while(mx&(mx-1))
    ++mx;
  tr.resize(2*mx);
  l.resize(2*mx);
  r.resize(2*mx);
  forn(i,mx){
    l[i+mx]=r[i+mx]=i;
    if(i<sz(mar))
      tr[i+mx]=nod(mar[i]);
  }
  for(in i=mx-1;i>=0;--i){
    l[i]=l[2*i];
    r[i]=r[2*i+1];
    tr[i]=tr[2*i];
    tr[i]+=tr[2*i+1];
  }
}
VVI lst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,q;
  cin>>n>>q;
  cin>>mar;
  assert(sz(mar)==n);
  build();
  lst.resize(n,VI(10,-1));
  forn(i,n){
    if(i){
      forn(j,10)
	lst[i][j]=lst[i-1][j];
    }
    lst[i][mar[i]-'0']=i;
  }
  in qsl,qsr;
  nod n1,n2,n3,n4;
  nod h2,h0,h1;
  h2.mcst[0][0]=1e6;
  h0.mcst[1][1]=1e6;
  h1.mcst[2][2]=1e6;
  forn(zz,q){
    cin>>qsl>>qsr;
    --qsl;
    --qsr;
    in cr=lst[qsr][7];
    if(cr<qsl){
      cout<<-1<<"\n";
      continue;
    }
    cr=lst[cr][1];
    if(cr<qsl){
      cout<<-1<<"\n";
      continue;
    }
    n4=rqr(cr+1,qsr);
    in pcr=cr;
    cr=lst[cr][0];
    if(cr<qsl){
      cout<<-1<<"\n";
      continue;
    }
    n3=rqr(cr+1,pcr-1);
    pcr=cr;
    cr=lst[cr][2];
    if(cr<qsl){
      cout<<-1<<"\n";
      continue;
    }
    n2=rqr(cr+1,pcr-1);
    n1=rqr(qsl,cr-1);
    n1+=h2;
    n1+=n2;
    n1+=h0;
    n1+=n3;
    n1+=h1;
    n1+=n4;
    cout<<n1.mcst[0][3]<<"\n";
  }
  return 0;
}