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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
const int s=1000000;
int n,x;
vector<bool> tkn;
vector<int> ttk;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  tkn.resize(s+1,0);
  cin>>n;
  forn(i,n){
    cin>>x;
    tkn[x]=1;
  }
  int ntt=0;
  for(int i=1;2*i<=s;i++){
    if(tkn[i] && tkn[s-i+1])
      ntt++;
  }
  for(int i=1;2*i<=s;i++){
    if(tkn[i] && !tkn[s-i+1])
      ttk.PB(s-i+1);
    if(!tkn[i] && tkn[s-i+1])
      ttk.PB(i);
    if(!tkn[i] && !tkn[s-i+1] && ntt>0){
      ntt--;
      ttk.PB(i);
      ttk.PB(s-i+1);
    }
  }
  cout<<sz(ttk)<<"\n";
  forv(i,ttk)
    cout<<ttk[i]<<" ";
  cout<<"\n";
  return 0;
}