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
const in mx=5000009LL;
VI pr;
VI tpr;
bool ispal(in a){
  pr.clear();
  while(a){
    pr.PB(a%10);
    a/=10;
  }
  tpr=pr;
  reverse(all(tpr));
  return tpr==pr;
}
VI isp;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in p,q;
  cin>>p>>q;
  in rt=1;
  isp=VI(mx,1);
  isp[0]=isp[1]=0;
  in psf=0;
  in palsf=0;
  for(in i=1;i<mx;i++){
    if(ispal(i))
      palsf++;
    if(isp[i]){
      psf++;
      for(in j=2*i;j<mx;j+=i)
	isp[j]=0;
    }
    if(q*psf<=p*palsf)
      rt=i;
  }
  cout<<rt<<endl;
  return 0;
}