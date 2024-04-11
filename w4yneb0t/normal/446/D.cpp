#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
struct mat{
  in n,m;
  vector<vector<double> > a;
  void ini(in pn, in pm){
    n=pn;
    m=pm;
    a=vector<vector<double> >(n,vector<double>(m,0));
  }
  mat operator*(const mat cp)const{
    mat r;
    assert(m==cp.n);
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
mat id(in s){
  mat r;
  r.ini(s,s);
  forn(i,s)
    r.a[i][i]=1;
  return r;
}
mat pw(mat x, in p){
  assert(x.n==x.m);
  vector<in> dg;
  while(p){
    dg.PB(p%2);
    p/=2;
  }
  mat r;
  r=id(x.n);
  for(in i=sz(dg)-1;i>=0;i--){
    r=r*r;
    if(dg[i])
      r=r*x;
  }
  return r;
}
vector<vector<double> > tr;
in roomc;
in wayc;
in steps;
vector<vector<in> > egs;
vector<in> trap;
mat mm;
set<in> done;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>roomc>>wayc>>steps;
  tr.resize(roomc,vector<double>(roomc,0));
  egs.resize(roomc);
  in ta,tb;
  trap.resize(roomc);
  forn(i,roomc)
    cin>>trap[i];
  forn(i,wayc){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(i,roomc){
    forv(j,egs[i]){
      tr[i][egs[i][j]]+=1;
    }
    done.clear();
    forv(j,egs[i]){
      if(done.find(egs[i][j])==done.end())
	tr[i][egs[i][j]]/=sz(egs[i]);
      done.insert(egs[i][j]);
    }
  }
  /*cout<<"at start"<<endl;
  forn(x,roomc){
    forn(y,roomc){
      cout<<x<<" "<<y<<" "<<tr[x][y]<<endl;
    }
  }*/
  for(in j=roomc-1;j>=0;j--){
    if(!trap[j]){
      forn(i,roomc){
	forn(k,roomc){
	  if(i==k && !trap[i])
	    continue;
	  tr[i][k]+=tr[i][j]*tr[j][k];
	}
      }
      forn(i,roomc)
	tr[i][j]=0;
      forn(i,roomc){
	if(trap[i])
	  continue;
	double totp=0;
	forn(k,roomc)
	  if(i!=k)
	    totp+=tr[i][k];
	forn(k,roomc)
	  tr[i][k]/=totp;
	tr[i][i]=0;
      }/*
      cout<<"after removing "<<j<<endl;
      forn(x,roomc){
	forn(y,roomc){
	  cout<<x<<" "<<y<<" "<<tr[x][y]<<endl;
	}
      }*/
    }
  }
  in tcount=0;
  vector<in> nbt;
  forn(i,roomc){
    if(trap[i]){
      nbt.PB(i);
      tcount++;
    }
  }
  mm.ini(tcount,tcount);
  forv(i,nbt){
    forv(j,nbt){
      mm.a[j][i]=tr[nbt[i]][nbt[j]];
    }
  }
  mm=pw(mm,steps-2);
  mat cp;
  cp.ini(tcount,1);
  forn(i,tcount)
    cp.a[i][0]=tr[0][nbt[i]];
  cp=mm*cp;
  cout<<cp.a[tcount-1][0]<<endl;
  return 0;
}