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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
void cln(vector<int>& a){
  in n=sz(a);
  in j;
  for(in i=n-5;i>=0;i--){
    j=i;
    while(a[j] && a[j+1]){
      a[j]=a[j+1]=0;
      j+=2;
      a[j]=1;
    }
  }
}
string ta,tb;
vector<int> a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>ta>>tb;
  forv(i,ta)
    a.PB(ta[i]-'0');
  forv(i,tb)
    b.PB(tb[i]-'0');
  reverse(all(a));
  reverse(all(b));
  in n=sz(a);
  if(sz(b)>n)
    n=sz(b);
  n+=10;
  while(sz(a)<n)
    a.PB(0);
  while(sz(b)<n)
    b.PB(0);
  cln(a);
  cln(b);
  for(in i=n-1;i>=0;i--){
    if(a[i]!=b[i]){
      if(a[i])
	cout<<">"<<endl;
      else
	cout<<"<"<<endl;
      return 0;
    }
  }
  cout<<"="<<endl;
  return 0;
}