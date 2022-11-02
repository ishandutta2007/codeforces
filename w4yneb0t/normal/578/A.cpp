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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in ta,tb;
  cin>>ta>>tb;
  if(ta<tb){
    cout<<-1<<endl;
    return 0;
  }
  double ota=ta;
  ta-=(ta%tb);
  if((ta/tb)%2==0)
    ta-=tb;
  double a=ta;
  double b=tb;
  cout<<setprecision(15)<<b*(ota+b)/(a+b)<<endl;
  return 0;
}