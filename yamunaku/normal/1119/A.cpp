#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> mac(n,-1),mic(n,IINF);
  int c;
  for(int i=0;i<n;i++){
    cin >> c;
    mac[c-1]=max(mac[c-1],i);
    mic[c-1]=min(mic[c-1],i);
  }
  pair<int,int> ma1={-1,-1},ma2={-1,-1},mi1={IINF,IINF},mi2={IINF,IINF};
  for(int i=0;i<n;i++){
    if(pair<int,int>(mac[i],i)>ma1){
      ma2=ma1;
      ma1={mac[i],i};
    }else if(pair<int,int>(mac[i],i)>ma2){
      ma2={mac[i],i};
    }
    if(pair<int,int>(mic[i],i)<mi1){
      mi2=mi1;
      mi1={mic[i],i};
    }else if(pair<int,int>(mic[i],i)<mi2){
      mi2={mic[i],i};
    }
  }
  int ans=0;
  if(ma1.second!=mi1.second){
    ans=ma1.first-mi1.first;
  }else{
    ans=max(ma1.first-mi2.first,ma2.first-mi1.first);
  }
  cout << ans << endl;
  return 0;
}