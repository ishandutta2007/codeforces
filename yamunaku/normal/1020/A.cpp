#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ab(a) max((a),-(a))

typedef long long LL;

int main(){
  LL n,h,a,b,k;
  cin >> n >> h >> a >> b >> k;
  LL ta,fa,tb,fb;
  for(int tc=0;tc<k;tc++){
    cin >> ta >> fa >> tb >> fb;
    if(fa>b&&fb>b){
      if(ta!=tb) cout << ab(ta-tb)+fa-b+fb-b << endl;
      else cout << ab(fa-fb) << endl;
    }else if(fa<a&&fb<a){
      if(ta!=tb) cout << ab(ta-tb)+a-fa+a-fb << endl;
      else cout << ab(fa-fb) << endl;
    }else{
      cout << ab(ta-tb)+ab(fa-fb) << endl;
    }
  }
  return 0;
}