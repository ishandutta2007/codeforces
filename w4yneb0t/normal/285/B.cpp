#include<iostream>
#include<algorithm>
#define forn(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int n,s,t;
  int p[100009];
  cin>>n>>s>>t;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }
  int m=0;
  int c=s;
  if(s==t){
    cout<<0<<endl;
    return 0;
  }
  while(m==0 || (c!=s && c!=t)){
    m++;
    c=p[c];
  }
  if(c==s)
    cout<<-1<<endl;
  else
    cout<<m<<endl;
  return 0;
}