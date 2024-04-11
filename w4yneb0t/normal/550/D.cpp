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
in cid[2][200];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in k;
  cin>>k;
  if(k%2==0){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  if(k==1){
    cout<<"2 1\n1 2\n";
    return 0;
  }
  in cct=7;
  forn(z,2)
    forn(i,k-1)
    cid[z][i]=cct++;
  cout<<2*k+4<<" "<<2+1+6*(k-1)+(k-1)*(k-2)-(k-1)<<endl;
  forn(i,k-1){
    cout<<1<<" "<<cid[0][i]<<endl;
    cout<<2<<" "<<cid[1][i]<<endl;
    cout<<3<<" "<<cid[0][i]<<endl;
    cout<<4<<" "<<cid[0][i]<<endl;
    cout<<5<<" "<<cid[1][i]<<endl;
    cout<<6<<" "<<cid[1][i]<<endl;
  }
  cout<<1<<" "<<2<<endl;
  cout<<3<<" "<<4<<endl;
  cout<<5<<" "<<6<<endl;
  forn(z,2){
    forn(i,k-1){
      forn(j,i){
	if(j%2==0 && j+1==i)
	  continue;
	cout<<cid[z][j]<<" "<<cid[z][i]<<endl;
      }
    }
  }
  return 0;
}