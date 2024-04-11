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
vector<int> mnb,lst;
const in lg=1000009LL;
VI bnb;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  mnb.resize(lg,100);
  lst.resize(lg);
  mnb[0]=0;
  lst[0]=0;
  bnb.PB(0);
  in cr=0;
  while(bnb.back()<=lg){
    bnb.PB(bnb[cr]*10);
    bnb.PB(bnb[cr]*10+1);
    cr++;
  }
  forv(i,bnb){
    forn(j,lg-bnb[i]){
      if(mnb[j+bnb[i]]>mnb[j]+1){
	mnb[j+bnb[i]]=mnb[j]+1;
	lst[j+bnb[i]]=bnb[i];
      }
    }
  }
  in n;
  cin>>n;
  cout<<mnb[n]<<endl;
  while(n){
    cout<<lst[n]<<" ";
    n-=lst[n];
  }
  cout<<endl;
  return 0;
}