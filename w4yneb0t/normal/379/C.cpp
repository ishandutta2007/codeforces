#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
struct usr{
  in a;
  in id;
  bool operator<(const usr cp)const{
    if(a!=cp.a)
      return a<cp.a;
    return id<cp.id;
  }
};
in n;
usr usrs[300009];
in b[300009];
int main(){
  cin>>n;
  forn(i,n){
    cin>>usrs[i].a;
    usrs[i].id=i;
  }
  sort(usrs,usrs+n);
  in cn=-2;
  forn(i,n){
    cn++;
    if(cn<usrs[i].a)
      cn=usrs[i].a;
    b[usrs[i].id]=cn;
  }
  forn(i,n)
    cout<<b[i]<<" ";
  cout<<endl;
  return 0;
}