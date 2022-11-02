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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VVI isp;
const in mx=505;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  isp.resize(mx,VI(mx,0));
  isp[0][0]=1;
  in c;
  forn(z,n){
    cin>>c;
    for(in i=mx-1-c;i>=0;--i){
      for(in j=min(mx-1-c,mx-1-i-c);j>=0;--j){
	isp[i+c][j]|=isp[i][j];
	isp[i][j+c]|=isp[i][j];
      }
    }
  }
  in ct=0;
  forn(x,k+1){
    if(isp[k-x][x])
      ++ct;
  }
  cout<<ct<<endl;
  forn(x,k+1){
    if(isp[k-x][x])
      cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}