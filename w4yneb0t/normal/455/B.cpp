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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,k;
struct tri{
  vector<int> nxt;
  in pr;
  void ini(){
    nxt.resize(26,-1);
  }
};
vector<tri> tris;
vector<int> cw1,cl1;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  //first can force win and loss: first
  //                win           first if k%2==1, second otherwise
  //                        loss: second
  //                            : second
  cin>>n>>k;
  tri tp;
  tp.ini();
  tris.PB(tp);
  string s;
  in ind;
  forn(i,n){
    cin>>s;
    ind=0;
    forv(ins,s){
      if(tris[ind].nxt[s[ins]-'a']==-1){
	tris[ind].nxt[s[ins]-'a']=sz(tris);
	tris.PB(tp);
	tris[sz(tris)-1].pr=ind;
      }
      ind=tris[ind].nxt[s[ins]-'a'];
    }
  }
  in mtr=sz(tris);
  cw1.resize(mtr,0);
  cl1.resize(mtr,0);
  in ncd;
  for(in i=mtr-1;i>0;i--){
    ncd=0;
    forn(j,26)
      ncd|=(tris[i].nxt[j]!=-1);
    if(ncd==0)
      cl1[i]=1;
    if(!cw1[i])
      cw1[tris[i].pr]=1;
    if(!cl1[i])
      cl1[tris[i].pr]=1;
  }
  if(!cw1[0])
    cout<<"Second"<<endl;
  else{
    if(cl1[0] || k%2==1)
      cout<<"First"<<endl;
    else
      cout<<"Second"<<endl;
  }
  return 0;
}