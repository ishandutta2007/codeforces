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
void fl(){
  cout<<-1<<endl;
  exit(0);
}
in tr(in n, in a){
  if(n==a)
    return 1;
  cout<<n<<" ";
  return 0;
}
void ex(in n, in m, in a){
  in bd=0;
  bd+=tr(n*n+m*m,a);
  bd+=tr(n*n-m*m,a);
  bd+=tr(2*n*m,a);
  assert(bd==1);
  cout<<endl;
  exit(0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a;
  cin>>a;
  if(a==1)
    fl();
  if(a==2)
    fl();
  if(a%2==0)
    ex(a/2,1,a);
  ex((a+1)/2,(a-1)/2,a);
  return 0;
}