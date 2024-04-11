#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll md=1000000007;
ll inv(ll a){
  ll r=1;
  ll tp=1;
  ll p=md-2;
  while(tp<p)
    tp*=2;
  while(p>0){
    r*=r;
    r%=md;
    if(p>=tp){
      r*=a;
      r%=md;
      p-=tp;
    }
    tp/=2;
  }
  return r;
}
ll fc(ll a){
  if(a==0)
    return 1;
  return (fc(a-1)*a)%md;
}
ll pw(ll a){
  if(a==-1)
    return 1;
  if(a==0)
    return 1;
  return (pw(a-1)*2)%md;
}
int main(){
  ll n,m;
  cin>>n>>m;
  int tk[1009];
  int tlp;
  for(int i=0;i<n;i++){
    tk[i]=0;
  }
  for(int i=0;i<m;i++){
    cin>>tlp;
    tk[tlp-1]=1;
  }
  tk[n]=1;
  int rl=0;
  int i;
  ll totr=fc(n-m);
  for(i=0;i<n;i++){
    if(tk[i]==1){
      totr*=inv(fc(i));
      totr%=md;
      break;
    }
  }
  for(;i<n;i++){
    if(tk[i]==1){
      totr*=inv(fc(rl));
      totr%=md;
      totr*=pw(rl-1);
      totr%=md;
      rl=0;
    }
    else
      rl++;
  }
  totr*=inv(fc(rl));
  totr%=md;
  cout<<totr<<endl;
  return 0;
}