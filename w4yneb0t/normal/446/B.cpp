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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
// dec a rows and b columns
// -b*a*p
// dec the same column x times
// -x*(x-1)/2*p*n
// dec the same row x times
// -x*(x-1)/2*p*m
in n,m;
vector<vector<in> > a;
in k,p;
vector<in> rows,cols;
priority_queue<in> pq;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m>>k>>p;
  a.resize(n,vector<in>(m));
  forn(i,n)
    forn(j,m)
    cin>>a[i][j];
  rows.resize(k+1);
  cols.resize(k+1);
  rows[0]=0;
  cols[0]=0;
  forn(i,n){
    in sm=0;
    forn(j,m)
      sm+=a[i][j];
    pq.push(sm);
  }
  in tp;
  for(in cc=1;cc<=k;cc++){
    tp=pq.top();
    pq.pop();
    rows[cc]=rows[cc-1]+tp;
    pq.push(tp-m*p);
  }
  while(!pq.empty())
    pq.pop();
  forn(j,m){
    in sm=0;
    forn(i,n)
      sm+=a[i][j];
    pq.push(sm);
  }
  for(in cc=1;cc<=k;cc++){
    tp=pq.top();
    pq.pop();
    cols[cc]=cols[cc-1]+tp;
    pq.push(tp-n*p);
  }
  in best=-1000000000000000000LL;
  forn(i,k+1){
    if(rows[i]+cols[k-i]-i*(k-i)*p>best)
      best=rows[i]+cols[k-i]-i*(k-i)*p;
  }
  cout<<best<<endl;
  return 0;
}