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
VI myr;
in n,m;
vector<double> tpr[2];
in mxs;
vector<double> num;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  if(m==1){
    cout<<1<<endl;
    return 0;
  }
  myr=VI(n);
  forn(i,n){
    cin>>myr[i];
    --myr[i];
  }
  mxs=(m-1)*n+3;
  forn(z,2)
    tpr[z].resize(mxs,0);
  in sw=0;
  in nw=0;
  tpr[sw][0]=1;
  double ttf=1.0/(m-1);
  forn(i,n){
    sw=i%2;
    nw=!sw;
    double csm=0;
    forn(j,mxs){
      csm+=ttf*tpr[sw][j];
      if(j-m>=0)
	csm-=ttf*tpr[sw][j-m];
      tpr[nw][j]=csm;
      if(j-myr[i]>=0)
	tpr[nw][j]-=ttf*tpr[sw][j-myr[i]];
    }
  }
  in mytot=0;
  forn(i,n)
    mytot+=myr[i];
  double tpb=0;
  forn(i,mytot)
    num.PB(tpr[nw][i]);
  sort(all(num));
  forv(i,num)
    tpb+=num[i];
  cout<<setprecision(15)<<(1+(m-1)*tpb)<<endl;
  return 0;
}