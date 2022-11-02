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
void nop(){
  printf("NO\n");
  exit(0);
}
in ab(in a){
  return a<0?-a:a;
}
VI isdon;
VI varv;
vector<map<in,in> > clauses;
vector<map<in,in> > vars;
set<in> unused;
queue<in> q;
void procclause(in val){
  if(isdon[val])
    return;
  if(sz(clauses[val])==0)
    nop();
  isdon[val]=1;
  in cvar=clauses[val].begin()->first;
  in ts=clauses[val].begin()->second;
  if(varv[cvar]==ts)
    return;
  if(varv[cvar]==(!ts))
    nop();
  varv[cvar]=ts;
  q.push(1);
  q.push(cvar);
}
void rmc(in val, in trm){
  clauses[val].erase(trm);
  if(sz(clauses[val])<=1){
    q.push(0);
    q.push(val);
  }
}
void procvar(in val){
  assert(varv[val]!=-1);
  fors(i,vars[val]){
    if(i->second==varv[val]){
      isdon[i->first]=1;
      continue;
    }
    rmc(i->first,val);
  }
}
void obv(){
  forv(i,clauses){
    if(sz(clauses[i])==1){
      q.push(0);
      q.push(i);
    }
  }
  in cv;
  forv(i,vars){
    if(!i)continue;
    if(sz(vars[i])==0){
      varv[i]=0;
      continue;
    }
    if(sz(vars[i])==1){
      q.push(1);
      q.push(i);
      varv[i]=vars[i].begin()->second;
      continue;
    }
    auto it=vars[i].begin();
    cv=it->second;
    ++it;
    if(cv==it->second){
      q.push(1);
      q.push(i);
      varv[i]=cv;
    }
  }
  in typ,val;
  bool hasfl=0;
  do{
    while(!q.empty()){
      typ=q.front();q.pop();
      val=q.front();q.pop();
      if(typ==0)
	procclause(val);
      else
	procvar(val);
    }
    hasfl=0;
    if(!unused.empty()){
      in i=*unused.begin();
      unused.erase(i);
      hasfl=1;
      if(varv[i]==-1){
	q.push(1);
	q.push(i);
	varv[i]=0;
      }
    }
  }while(hasfl);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  scanf("%d%d",&n,&m);
  clauses.resize(n);
  isdon=VI(n,0);
  vars.resize(m+1);
  varv.resize(m+1,-1);
  for(in i=1;i<=m;i++)
    unused.insert(i);
  forn(i,n){
    in cc;
    scanf("%d",&cc);
    in tp;
    forn(z,cc){
      scanf("%d",&tp);
      clauses[i][ab(tp)]=(tp>0);
      vars[ab(tp)][i]=(tp>0);
    }
  }
  obv();
  printf("YES\n");
  for(in i=1;i<=m;i++){
    printf("%d",varv[i]);
  }
  printf("\n");
  return 0;
}