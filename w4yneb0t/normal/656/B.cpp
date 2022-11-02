#include<iostream>
#include<iomanip>
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
const in mx=720720;
VI m,r;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  m.resize(n);
  r.resize(n);
  forn(i,n)
    cin>>m[i];
  forn(i,n)
    cin>>r[i];
  in tt=0;
  forn(i,mx){
    bool f=0;
    forn(j,n)
      if(i%m[j]==r[j])
	f=1;
    tt+=f;
  }
  cout<<setprecision(15);
  cout<<double(tt)/double(mx)<<endl;
  return 0;
}