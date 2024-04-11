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
  int a;
  int one=0,two=0;
  for(int i=0;i<n;i++){
    cin >> a;
    if(a==1){
      one++;
    }else{
      two++;
    }
  }
  vector<bool> p(400100,true);
  p[0]=false,p[1]=false;
  for(int i=2;i<400100;i++){
    if(p[i]){
      for(int j=2*i;j<400100;j+=i) p[j]=false;
    }
  }
  int now=0;
  for(int i=0;i<n;i++){
    if(p[now+1]){
      if(one>0){
        cout << 1 << " ";
        one--;
        now++;
      }else{
        cout << 2 << " ";
        two--;
        now+=2;
      }
    }else{
      if(two>0){
        cout << 2 << " ";
        two--;
        now+=2;
      }else{
        cout << 1 << " ";
        one--;
        now++;
      }
    }
  }
  return 0;
}