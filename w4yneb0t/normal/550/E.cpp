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
VI inp;
in zrc=0;
void mk1(in n){
  if(inp[n-1]!=0){
    if(n>1){
      cout<<"(";
      forn(i,n-1){
	cout<<inp[i];
	if(i+1<n-1)
	  cout<<"->";
      }
      cout<<")->1";
    }
    else
      cout<<1;
    return;
  }
  if(inp[n-2]==0){
    if(n>2){
      cout<<"(";
      forn(i,n-2){
	cout<<inp[i];
	if(i+1<n-2)
	  cout<<"->";
      }
      cout<<")->(0->0)";
    }
    else
      cout<<"(0->0)";
    return;
  }
  for(in i=n-2;i>=0;i--){
    if(inp[i]==0){
      forn(j,i){
	cout<<inp[j];
	cout<<"->";
      }
      cout<<"(";
      cout<<"0->(";
      cout<<"(";
      for(in j=i+1;j<n-1;j++){
	cout<<1;
	if(j+1<n-1)
	  cout<<"->";
      }
      cout<<")->0";
      cout<<")";
      cout<<")";
      return;
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  inp.resize(n);
  forn(i,n){
    cin>>inp[i];
    zrc+=(inp[i]==0);
  }
  if(inp.back()!=0){
    cout<<"NO"<<"\n";
    return 0;
  }
  if(zrc==2 && inp[sz(inp)-2]==0){
    cout<<"NO"<<"\n";
    return 0;
  }
  cout<<"YES"<<"\n";
  if(n==1){
    cout<<"0\n";
    return 0;
  }
  n--;
  zrc--;
  inp.pop_back();
  cout<<"(";
  mk1(n);
  cout<<")->0\n";
  return 0;
}