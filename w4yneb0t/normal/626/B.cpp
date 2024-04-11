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
vector<VVI> isp;
queue<in> q;
void ad(const in& r, const in& g, const in& b){
  if(isp[r][g][b])
    return;
  isp[r][g][b]=1;
  q.push(r);
  q.push(g);
  q.push(b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in junk;
  cin>>junk;
  in r,g,b;
  string s;
  cin>>s;
  r=g=b=0;
  forv(i,s){
    if(s[i]=='R')
      ++r;
    if(s[i]=='B')
      ++b;
    if(s[i]=='G')
      ++g;
  }
  isp.resize(204,VVI(204,VI(204,0)));
  isp[r][g][b]=1;
  q.push(r);
  q.push(g);
  q.push(b);
  while(!q.empty()){
    r=q.front();
    q.pop();
    g=q.front();
    q.pop();
    b=q.front();
    q.pop();
    if(!isp[r][g][b])
      continue;
    if(r>=2)
      ad(r-1,g,b);
    if(g>=2)
      ad(r,g-1,b);
    if(b>=2)
      ad(r,g,b-1);
    if(r && g)
      ad(r-1,g-1,b+1);
    if(r && b)
      ad(r-1,g+1,b-1);
    if(g && b)
      ad(r+1,g-1,b-1);
  }
  if(isp[0][0][1])
    cout<<"B";
  if(isp[0][1][0])
    cout<<"G";
  if(isp[1][0][0])
    cout<<"R";
  cout<<endl;
  return 0;
}