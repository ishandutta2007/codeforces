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
map<char,in> idof;
VI ded;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ded.resize(4);
  string s;
  cin>>s;
  forv(i,s){
    if(s[i]=='!')
      ++ded[i%4];
    else
      idof[s[i]]=i%4;
  }
  cout<<ded[idof['R']]<<" ";
  cout<<ded[idof['B']]<<" ";
  cout<<ded[idof['Y']]<<" ";
  cout<<ded[idof['G']]<<endl;
  return 0;
}