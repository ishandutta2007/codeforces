#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),(-a))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  int ph,w,h;
  cin >> w >> h;
  ph=max(w,h);
  for(int i=1;i<n;i++){
    cin >> w >> h;
    if(ph>=max(w,h)){
      ph=max(w,h);
    }else if(ph>=min(w,h)){
      ph=min(w,h);
    }else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}