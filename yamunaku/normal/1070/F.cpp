#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> a0(n),a1(n),a2(n),a3(n);
  int k0=0,k1=0,k2=0,k3=0;
  string s;
  int a;
  for(int i=0;i<n;i++){
    cin >> s >> a;
    if(s=="00"){
      a3[k3]=a;
      k3++;
    }else if(s=="01"){
      a1[k1]=a;
      k1++;
    }else if(s=="10"){
      a2[k2]=a;
      k2++;
    }else{
      a0[k0]=a;
      k0++;
    }
  }
  sort(a1.begin(),a1.begin()+k1,greater<int>());
  sort(a2.begin(),a2.begin()+k2,greater<int>());
  LL total=0;
  for(int i=0;i<n;i++){
    total+=a0[i];
  }
  if(k1>k2){
    for(int i=0;i<k2;i++){
      total+=a1[i]+a2[i];
    }
    for(int i=0;i<k1-k2;i++){
      a3[k3]=a1[k2+i];
      k3++;
    }
  }else{
    for(int i=0;i<k1;i++){
      total+=a1[i]+a2[i];
    }
    for(int i=0;i<k2-k1;i++){
      a3[k3]=a2[k1+i];
      k3++;
    }
  }
  sort(a3.begin(),a3.begin()+k3,greater<int>());
  for(int i=0;i<min(k0,k3);i++){
    total+=a3[i];
  }
  cout << total << endl;
  return 0;
}