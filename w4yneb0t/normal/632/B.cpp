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
VI st;
VI as;
string tp;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  st.resize(n);
  as.resize(n);
  forn(i,n)
    cin>>st[i];
  cin>>tp;
  forn(i,n)
    as[i]=(tp[i]=='B');
  in tot=0;
  in hav=0;
  forn(i,n){
    tot+=st[i];
    hav+=as[i]*st[i];
  }
  in ctot=0;
  in chav=0;
  in bst=max(hav,tot-hav);
  in cval;
  forn(i,n){
    ctot+=st[i];
    chav+=as[i]*st[i];
    cval=(hav-chav)+(ctot-chav);
    cval=max(cval,tot-cval);
    bst=max(bst,cval);
  }
  cout<<bst<<endl;
  return 0;
}