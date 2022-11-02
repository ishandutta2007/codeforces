#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2e5+10;

int T;
string s;
ll x[n], y[n];
ll mxX[n], mxY[n], revY[n], revX[n];
ll miX[n], miY[n], reviY[n], reviX[n];

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

ll area(ll xmi, ll xma, ll ymi, ll yma){
  return (xma-xmi+1) * (yma-ymi+1);
}

int main(){
  cin >> T;
  while(T--){
    cin >> s;
    for(int i=0; i<sz(s); i++){
      mxX[i+1] = mxY[i+1] = revY[i+1] = revX[i+1] = 0;
      x[i+1] = y[i+1] = 0;
      switch(s[i]){
      case 'W': y[i+1] = 1; break;
      case 'S': y[i+1] = -1; break;
      case 'A': x[i+1] = -1; break;
      case 'D': x[i+1] = 1; break;
      }
      x[i+1] += x[i];
      y[i+1] += y[i];
    }
    /*
    mxX[1] = miX[1] = x[1];
    mxY[1] = miY[1] = y[1];
    */
    for(int i=1; i<=sz(s); i++){
      mxX[i] = max(mxX[i-1], x[i]);
      mxY[i] = max(mxY[i-1], y[i]);
      miX[i] = min(miX[i-1], x[i]);
      miY[i] = min(miY[i-1], y[i]);
    }
    reviX[sz(s)] = revX[sz(s)] = x[sz(s)];
    reviY[sz(s)] = revY[sz(s)] = y[sz(s)];
    for(int i=sz(s)-1; i>=0; i--){
      revX[i] = max(revX[i+1], x[i]);
      revY[i] = max(revY[i+1], y[i]);
      reviX[i] = min(reviX[i+1], x[i]);
      reviY[i] = min(reviY[i+1], y[i]);
    }
    /*
    for(int i=0; i<sz(s)+1; i++){
      cout << x[i] << " " << y[i] << endl;
    }
    for(int i=0; i<sz(s)+1; i++){
      cout << mxX[i] << " " << miX[i] << endl;
    }
    */
    ll best = area(miX[sz(s)], mxX[sz(s)], miY[sz(s)], mxY[sz(s)]);
    for(int i=0; i<sz(s); i++){
      for(int j=0; j<4; j++){
        int dx = X[j];
        int dy = Y[j];
        best = min(best, area(min(miX[i], reviX[i]+dx), max(mxX[i], revX[i]+dx), min(miY[i], reviY[i]+dy), max(mxY[i], revY[i]+dy)));
      }
    }
    cout << best << "\n";
  }

  return 0;
}