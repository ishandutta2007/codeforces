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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  if(n%2==0){
    cout<<n/2<<endl;
    forn(z,n/2)
      cout<<"2 ";
    cout<<endl;
  }
  else{
    cout<<n/2<<endl;
    cout<<"3 ";
    forn(z,n/2-1)
      cout<<"2 ";
    cout<<endl;
  }
  return 0;
}