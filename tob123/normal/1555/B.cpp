#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int W, H, x0, y0, x1, y1, w, h;
    cin >> W >> H;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> w >> h;
    int best = 1e9;
    if(W-(x1-x0) >= w){
      best = max(0, w-max(x0, W-x1));
    }
    if(H-(y1-y0) >= h){
      best = min(best, max(0, h-max(y0, H-y1)));
    }
    if(best == 1000000000)
      best = -1;
    cout << best << "\n";
  }
}