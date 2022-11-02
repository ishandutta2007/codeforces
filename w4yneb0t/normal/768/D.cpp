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
const in eps=1e-11;
vector<double> qr;
VI ans;
double pb[2][1009];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in k,q;
  cin>>k>>q;
  ans.resize(q,-1);
  in nw=0;
  in sw=1;
  qr.resize(q);
  forn(z,q){
    cin>>qr[z];
    qr[z]/=2000;
  }
  pb[nw][0]=1;
  in tg=q;
  double cc;
  in its=0;
  while(tg){
    ++its;
    swap(nw,sw);
    forn(i,k+1)
      pb[nw][i]=0;
    forn(i,k+1){
      pb[nw][i]+=pb[sw][i]*i/double(k);
      pb[nw][i+1]+=pb[sw][i]*(k-i)/double(k);
    }
    cc=pb[nw][k];
    forn(i,q){
      if(ans[i]==-1 && qr[i]-eps<cc){
	--tg;
	ans[i]=its;
      }
    }
  }
  forn(i,q)
    cout<<ans[i]<<"\n";
  return 0;
}