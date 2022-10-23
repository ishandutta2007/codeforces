#include<bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
using ll=long long;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
int main(){
  ll t;cin>>t;
  while(t--){
    string a,b;cin>>a>>b;
    auto sz=[](string x){
      if(x.back()=='M')return 0;
      if(x.back()=='S')return -(int)x.size();
      if(x.back()=='L')return (int)x.size();
    };
    if(sz(a)==sz(b))cout<<"="<<endl;
    else if(sz(a)<sz(b))cout<<"<"<<endl;
    else cout<<">"<<endl;
  }
  return 0;
}