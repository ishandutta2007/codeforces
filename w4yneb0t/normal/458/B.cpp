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
in best;
in m,n;
void cd(vector<in>& a, vector<in>& b){
  in sf=0;
  in m=sz(a);
  in n=sz(b);
  in sa=0;
  forn(i,m)
    sa+=a[i];
  sf=sa;
  forn(i,n-1){
    if(b[i]>sa)
      sf+=sa;
    else
      sf+=b[i];
  }
  if(sf<best)
    best=sf;
}
in sa=0;
in sb=0;
vector<in> a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>m>>n;
  a.resize(m);
  forn(i,m)
    cin>>a[i];
  b.resize(n);
  forn(i,n)
    cin>>b[i];
  sort(all(a));
  sort(all(b));
  forn(i,m)
    sa+=a[i];
  forn(i,n)
    sb+=b[i];
  best=sa+sb;
  cd(a,b);
  cd(b,a);
  cout<<best<<endl;
  return 0;
}