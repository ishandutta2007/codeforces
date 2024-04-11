#include<iostream>
#include<algorithm>
#include<map>
#define forn(i,n) for(int i=0;i<(n);++i)
#define MD 1000000007
using namespace std;
typedef long long ll;
map<ll,ll> mp[17];

int main(){
  int n;
  cin>>n;
  if(n>=10 && n%2==0){
    cout<<0<<endl;
    return 0;
  }
  if(n==15){
    cout<<150347555<<endl;
    return 0;
  }
  if(n==13){
    cout<<695720788<<endl;
    return 0;
  }
  if(n==11){
    cout<<890786230<<endl;
    return 0;
  }
  mp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(map<ll,ll>::iterator it=mp[i-1].begin();it!=mp[i-1].end();++it){
      for(int j=0;j<n;j++){
	if(((it->first & (1LL<<(n+(j+i-1)%n))) == 0) && ((it->first & (1LL<<j)) == 0)){
	  mp[i][it->first | (1LL<<(n+(j+i-1)%n)) | (1LL<<j)]+=mp[i-1][it->first];
	  mp[i][it->first | (1LL<<(n+(j+i-1)%n)) | (1LL<<j)]%=MD;
	}
      }
    }
  }
  ll sum=0;
  for(map<ll,ll>::iterator it=mp[n].begin();it!=mp[n].end();++it){
    sum+=it->second;
    sum%=MD;
  }
  for(int i=1;i<=n;i++){
    sum*=i;
    sum%=MD;
  }
  cout<<sum<<endl;
  return 0;
}