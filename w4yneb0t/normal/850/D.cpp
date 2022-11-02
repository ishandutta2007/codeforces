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
const in mxpp=62;
const in mxsc=32;
VVI nu(VVI isp, in a, VVI& prv){
  VVI res(mxpp,VI(mxpp*mxsc));
  prv.resize(mxpp,VI(mxpp*mxsc,-1));
  forn(op,mxpp-1){
    forn(osc,mxpp*mxsc){
      if(!isp[op][osc])
	continue;
      for(in nup=1;nup+op<mxpp;++nup){
	if(nup*a+osc>=mxpp*mxsc)
	  break;
	if(nup*a+osc<(op+nup)*(op+nup-1)/2)
	  break;
	res[nup+op][nup*a+osc]=1;
	prv[nup+op][nup*a+osc]=nup;
      }
    }
  }
  return res;
}
vector<VVI> prv;
vector<VVI> oisp;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>m;
  VI a(m);
  forn(i,m)
    cin>>a[i];
  sort(all(a));
  prv.resize(m);
  VVI isp(mxpp,VI(mxpp*mxsc));
  isp[0][0]=1;
  forn(i,m){
    isp=nu(isp,a[i],prv[i]);
    oisp.PB(isp);
  }
  in n=m;
  while(n<mxpp && !isp[n][n*(n-1)/2])
    ++n;
  if(n==mxpp){
    cout<<"=("<<endl;
    return 0;
  }
  cout<<n<<endl;
  VI prc;
  in curp=n;
  in curs=n*(n-1)/2;
  in tk;
  in cnu=m-1;
  while(cnu>=0){
    assert(oisp[cnu][curp][curs]);
    tk=prv[cnu][curp][curs];
    assert(tk!=-1);
    forn(z,tk)
      prc.PB(a[cnu]);
    curs-=a[cnu]*tk;
    curp-=tk;
    --cnu;
  }
  sort(all(prc));
  VVI rs(n,VI(n));
  VI lft(n);
  forn(i,n)
    lft[i]=n-1-prc[i];
  VI done(n);
  forn(z,n){
    in mxd=-1;
    forn(i,n){
      if(!done[i])
	mxd=max(mxd,prc[i]);
    }
    forn(i,n){
      if(!done[i] && prc[i]==mxd){
	done[i]=1;
	VI usd(n);
	forn(j,n){
	  if(done[j])
	    usd[j]=1;
	}
	in mx;
	usd[i]=1;
	while(prc[i]>0){
	  mx=-1;
	  forn(j,n){
	    if(!usd[j])
	      mx=max(mx,lft[j]);
	  }
	  assert(mx>-1);
	  forn(j,n){
	    if(!usd[j] && lft[j]==mx){
	      --lft[j];
	      --prc[i];
	      usd[j]=1;
	      rs[i][j]=1;
	      break;
	    }
	  }
	}
	forn(j,n){
	  if(!usd[j]){
	    --lft[i];
	    rs[j][i]=1;
	    --prc[j];
	  }
	}
	break;
      }
    }
  }
  forn(i,n){
    forn(j,n){
      cout<<rs[i][j];
    }
    cout<<endl;
  }
  return 0;
}