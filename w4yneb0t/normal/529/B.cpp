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
VI w,h;
in n,bst;
VI tp;
void trb(in mx){
  in ml=n/2;
  in tw=0;
  tp.clear();
  forn(i,n){
    if(h[i]>mx && w[i]>mx)
      return;
    if(w[i]>mx){
      tw+=w[i];
      continue;
    }
    if(h[i]>mx){
      --ml;
      tw+=h[i];
      continue;
    }
    if(w[i]<=h[i]){
      tw+=w[i];
      continue;
    }
    tw+=w[i];
    tp.PB(w[i]-h[i]);
  }
  sort(all(tp));
  reverse(all(tp));
  if(ml<0)
    return;
  forn(i,min(ml,sz(tp)))
    tw-=tp[i];
  bst=min(bst,tw*mx);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  bst=1e15;
  w.resize(n);
  h.resize(n);
  forn(i,n)
    cin>>w[i]>>h[i];
  forn(i,n){
    trb(w[i]);
    trb(h[i]);
  }
  cout<<bst<<endl;
  return 0;
}