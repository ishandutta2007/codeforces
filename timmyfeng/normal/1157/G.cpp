#include<bits/stdc++.h>
using namespace std;
const int N=200;
bool a[N][N],r[N],c[N];
int n,m;
void invr(int i){
 r[i]^=true;
 for(int j=0;j<m;++j)
  a[i][j]^=true;
}
void invc(int j){
 c[j]^=true;
 for(int i=0;i<n;++i)
  a[i][j]^=true;
}
int main(){
 cin>>n>>m;
 for(int i=0;i<n;++i)
  for(int j=0;j<m;++j)
   cin>>a[i][j];
 for(int k:{0,n-1}){
  for(int j=0;j<m;++j)
   if(a[k][j])
    invc(j);
  bool d=false;
  for(int i=0;i<n;++i){
   if(a[i][0]!=d)
    invr(i);
   d|=(count(a[i],a[i]+m,d)<m);
  }
  bool l=true;
  int x=0;
  for(int i=0;i<n;++i)
   for(int j=0;j<m;++j)
    l&=(a[i][j]>=x),x=a[i][j];
  if(l){
   cout<<"YES\n";
   for(int i=0;i<n;++i)
    cout<<r[i];
   cout<<"\n";
   for(int j=0;j<m;++j)
    cout<<c[j];
   exit(0);
  }
 }
 cout<<"NO";
}