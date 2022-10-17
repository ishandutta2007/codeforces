#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct num{
  int nu;
  int te;
  bool operator<(const struct num & right) const{
    return nu<right.nu;
  }
};

int main(){
  int n;
  cin >> n;
  int a;
  vector<struct num> x(2*n);
  for(int i=0;i<n;i++){
    cin >> a;
    x[i]={a,0};
  }
  for(int i=0;i<n;i++){
    cin >> a;
    x[n+i]={a,1};
  }
  sort(x.begin(),x.end());
  LL score=0;
  for(int i=0;i<2*n;i++){
    if(x[2*n-1-i].te==i%2){
      score+=x[2*n-1-i].nu*(1-i%2*2);
    }
  }
  cout << score << endl;
  return 0;
}