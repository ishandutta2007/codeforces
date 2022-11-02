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
typedef pair<in,in> PII;
VI mar;
VI mst,msid;
vector<vector<PII> > mad;
bool isb(in a, in b, in fc){
  return b*fc<=a;
}
VI slw;
in tad(in st, const vector<PII>& v, in fc){
  in r=0;
  forv(i,v){
    if(!isb(st+v[i].first,st,fc))
      break;
    st+=v[i].first;
    ++r;
  }
  return r;
}
bool isp(in gl, in fc){
  in sf=0;
  forv(i,mar){
    sf+=tad(mar[i],mad[i],fc);
  }
  return sf>=gl;
}
struct rt{
  in u,d;
  rt(in pu=0, in pd=0){
    u=pu;
    d=pd;
  }
  bool operator<(const rt cp)const{
    return u*cp.d>cp.u*d;
  }
};
VI nxid;
set<pair<rt,in> > nn;
void opsl(in gl){
  nxid.resize(sz(mar),0);
  forv(i,mar){
    if(sz(mad[i])!=0){
      nn.insert(MP(rt(mad[i][0].first,mar[i]),i));
    }
  }
  set<pair<rt,in> >::iterator it;
  in id;
  forn(z,gl){
    assert(!nn.empty());
    it=nn.begin();
    id=it->second;
    nn.erase(it);
    if(mad[id][nxid[id]].second==msid[id])
      cout<<(mad[id][nxid[id]].second)<<" ";
    else
      slw.PB(mad[id][nxid[id]].second);
    mar[id]+=mad[id][nxid[id]].first;
    ++nxid[id];
    if(nxid[id]<sz(mad[id]))
      nn.insert(MP(rt(mad[id][nxid[id]].first,mar[id]),id));
  }
}
vector<PII> mpl;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in k,n,m;
  cin>>k>>n>>m;
  mar.resize(k);
  mst.resize(k,0);
  msid.resize(k);
  mad.resize(k);
  forn(i,k)
    cin>>mar[i];
  in ttyp,ta,tb;
  forn(z,n){
    cin>>ttyp>>ta>>tb;
    --ta;
    if(ttyp==1){
      if(mst[ta]<tb && mar[ta]<tb){
	mst[ta]=tb;
	msid[ta]=z+1;
      }
    }
    if(ttyp==2){
      mad[ta].PB(MP(tb,z+1));
    }
    if(ttyp==3){
      mpl.PB(MP(tb,z+1));
    }
  }
  forn(i,k){
    if(mst[i]==0)
      continue;
    mad[i].PB(MP(mst[i]-mar[i],msid[i]));
  }
  in avb=0;
  forn(i,k){
    avb+=sz(mad[i]);
  }
  avb+=sz(mpl);
  m=min(m,avb);
  sort(all(mpl));
  reverse(all(mpl));
  forn(i,k){
    sort(all(mad[i]));
    reverse(all(mad[i]));
  }
  in mn=-1;
  in mx=min(sz(mpl),m);
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(isp(m-md,mpl[md].first))
      mx=md;
    else
      mn=md;
  }
  cout<<m<<"\n";
  opsl(m-mx);
  forv(i,slw)
    cout<<slw[i]<<" ";
  forn(i,mx)
    cout<<mpl[i].second<<" ";
  cout<<"\n";
  return 0;
}