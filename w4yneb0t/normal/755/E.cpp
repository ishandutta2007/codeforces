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
void imp(){
  cout<<-1<<endl;
  exit(0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  if(k>3)
    imp();
  if(k<2)
    imp();
  if(n<4)
    imp();
  if(n==4){
    if(k!=3)
      imp();
    cout<<"3\n1 2\n2 3\n3 4\n";
    return 0;
  }
  if(k==2){
    cout<<n-1<<endl;
    for(in i=1;i<n;++i){
      cout<<i<<" "<<i+1<<endl;
    }
    return 0;
  }
  in bg=n-3;
  cout<<2+bg+bg*(bg-1)/2<<"\n";
  cout<<"1 2\n2 3\n";
  for(in i=4;i<=n;++i)
    cout<<"3 "<<i<<"\n";
  for(in i=4;i<=n;++i){
    for(in j=i+1;j<=n;++j){
      cout<<i<<" "<<j<<"\n";
    }
  }
  return 0;
}