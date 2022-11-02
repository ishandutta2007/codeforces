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
void imp(){
  cout<<-1<<endl;
  exit(0);
}
double mn=0;
double mx=1e9;
void pc(in x, in vx, in tx1, in tx2){
  if(vx==0){
    if(x>tx1 && x<tx2)
      return;
    else
      imp();
  }
  if(vx<0){
    vx=-vx;
    x=-x;
    tx1=-tx1;
    tx2=-tx2;
    swap(tx1,tx2);
  }
  if(x>=tx2)
    imp();
  mx=min(mx,(tx2-x)/double(vx));
  if(x<=tx1)
    mn=max(mn,(tx1-x)/double(vx));
}
in tx1,tx2,ty1,ty2;
void pm(){
  in x,y,vx,vy;
  cin>>x>>y>>vx>>vy;
  pc(x,vx,tx1,tx2);
  pc(y,vy,ty1,ty2);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout<<setprecision(15);
  in n;
  cin>>n;
  cin>>tx1>>ty1>>tx2>>ty2;
  forn(zz,n){
    pm();
  }
  const in EPS=3e-13;
  if(mx>mn*(1+EPS))
    cout<<mn<<endl;
  else
    imp();
  return 0;
}