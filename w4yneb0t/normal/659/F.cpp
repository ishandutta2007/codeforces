#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define x first
#define y second
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
VVI d={{0,1},{1,0},{0,-1},{-1,0}};
struct unifnd{
  VVI ht,msz,act;
  vector<vector<PII> > pr;
  PII fnd(PII a){
    PII ta=a;
    while(a!=pr[a.x][a.y])a=pr[a.x][a.y];
    PII tt=ta;
    while(ta!=a){
      tt=pr[ta.x][ta.y];
      pr[ta.x][ta.y]=a;
      ta=tt;
    }
    return a;
  }
  in asz(PII a){
    a=fnd(a);
    return msz[a.x][a.y];
  }
  void uni(PII a, PII b){
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b.x][b.y]<ht[a.x][a.y])swap(a,b);
    pr[a.x][a.y]=b;
    ht[b.x][b.y]+=(ht[a.x][a.y]==ht[b.x][b.y]);
    msz[b.x][b.y]+=msz[a.x][a.y];
  }
  void ini(in n, in m){
    ht.resize(n,VI(m,0));
    act.resize(n,VI(m,0));
    pr.resize(n,vector<PII>(m));
    msz.resize(n,VI(m,1));
    forn(i,n){
      forn(j,m){
	pr[i][j]=MP(i,j);
      }
    }
  }
  in adv(PII a){
    act[a.x][a.y]=1;
    forn(i,4){
      if(act[a.x+d[i][0]][a.y+d[i][1]])
	uni(a,MP(a.x+d[i][0],a.y+d[i][1]));
    }
    return asz(a);
  }
};
unifnd mfd;
in n,m,k;
VVI mbd;
queue<PII> q;
void gog(in val, PII loc){
  in glc=k/val;
  mbd[loc.x][loc.y]=-1;
  q.push(loc);
  --glc;
  PII nb;
  while(glc){
    loc=q.front();
    q.pop();
    forn(i,4){
      if(!glc)
	break;
      nb=MP(loc.x+d[i][0],loc.y+d[i][1]);
      if(mbd[nb.x][nb.y]<val)
	continue;
      --glc;
      mbd[nb.x][nb.y]=-1;
      q.push(nb);
    }
  }
  cout<<"YES\n";
  n-=2;
  m-=2;
  for(in i=1;i<=n;++i){
    for(in j=1;j<=m;++j){
      if(mbd[i][j]==-1)
	cout<<val<<" ";
      else
	cout<<0<<" ";
    }
    cout<<"\n";
  }
  exit(0);
}
void trad(in val, PII loc){
  in t=mfd.adv(loc);
  if(k%val==0 && k/val<=t){
    gog(val,loc);
  }
}
vector<pair<in,PII> > ord;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  mbd.resize(n+2,VI(m+2));
  mbd[0]=mbd[n+1]=VI(m+2,0);
  for(in i=1;i<=n;++i){
    mbd[i][0]=mbd[i][m+1]=0;
    for(in j=1;j<=m;++j){
      cin>>mbd[i][j];
      ord.PB(MP(mbd[i][j],MP(i,j)));
    }
  }
  n+=2;
  m+=2;
  mfd.ini(n,m);
  sort(all(ord));
  reverse(all(ord));
  forv(i,ord){
    trad(ord[i].x,ord[i].y);
  }
  cout<<"NO\n";
  return 0;
}