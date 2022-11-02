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
void imp(){
  cout<<"Not unique\n";
  exit(0);
}
vector<string> bd;
VVI dg;
VVI d={{0,1},{1,0},{0,-1},{-1,0}};
string sg="<^>v";
queue<in> q;
void cdg(in ux, in uy){
  --dg[ux][uy];
  if(dg[ux][uy]==1){
    q.push(ux);
    q.push(uy);
  }
}
void rml(in ux, in uy){
  forn(i,4)
    cdg(ux+d[i][0],uy+d[i][1]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  bd.resize(n+2);
  for(in i=1;i<=n;++i){
    cin>>bd[i];
    bd[i]="*"+bd[i]+"*";
  }
  bd[0]=bd[n+1]=string(m+2,'*');
  dg.resize(n+2,VI(m+2,0));
  for(in i=1;i<=n;++i){
    for(in j=1;j<=m;++j){
      dg[i][j]=0;
      forn(dr,4)
	dg[i][j]+=(bd[i+d[dr][0]][j+d[dr][1]]=='.');
      if(dg[i][j]==1){
	q.push(i);
	q.push(j);
      }
    }
  }
  in ux,uy,cd;
  while(!q.empty()){
    ux=q.front();
    q.pop();
    uy=q.front();
    q.pop();
    if(bd[ux][uy]!='.')
      continue;
    cd=-1;
    forn(dr,4){
      if(bd[ux+d[dr][0]][uy+d[dr][1]]=='.')
	cd=dr;
    }
    if(cd==-1)
      imp();
    bd[ux][uy]=sg[cd];
    bd[ux+d[cd][0]][uy+d[cd][1]]=sg[(cd+2)%4];
    rml(ux,uy);
    rml(ux+d[cd][0],uy+d[cd][1]);
  }
  forv(i,bd){
    forv(j,bd[i]){
      if(bd[i][j]=='.')
	imp();
    }
  }
  for(in i=1;i<=n;++i){
    for(in j=1;j<=m;++j){
      cout<<bd[i][j];
    }
    cout<<"\n";
  }
  return 0;
}