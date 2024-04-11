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
  int x;
  cin >> x;
  vector<int> ans;
  int c=0;
  while(1){
    for(int i=0;i<=20;i++){
      if(x==(1<<i)-1)  goto next;
    }
    if(c%2==0){
      for(int i=19;i>=0;i--){
        if((x&(1<<i))==0){
          ans.push_back(i+1);
          x^=((1<<(i+1))-1);
          break;
        }
      }
    }else{
      x++;
    }
    c++;
  }
  next:
  cout << c << endl;
  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}