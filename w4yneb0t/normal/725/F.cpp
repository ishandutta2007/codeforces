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
VI bns;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in a1,b1,a2,b2;
  in fa=0;
  in fb=0;
  forn(z,n){
    cin>>a1>>b1>>a2>>b2;
    if(a1<=b2 && b1<=a2)
      continue;
    if(a1+b1<=a2+b2){
      if(a1>b2){
	fa+=a1;
	fb+=b2;
      }
      else{
	fb+=b1;
	fa+=a2;
      }
      continue;
    }
    fa+=a1+a2;
    bns.PB(b1+a1);
    bns.PB(b2+a2);
  }
  sort(all(bns));
  reverse(all(bns));
  forv(i,bns){
    if(i%2==1)
      fb+=bns[i];
  }
  cout<<fa-fb<<endl;
  return 0;
}