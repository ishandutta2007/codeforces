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
  int n, C, m;
  cin >> n >> C;
  vector<int> c(n);
  vector<ll> hd(n);
  vector<int> bestI(C+1, -1);
  for(int i=0; i<n; i++){
    ll h, d;
    cin >> c[i] >> h >> d;
    hd[i] = h*d;
    if(bestI[c[i]] == -1 || hd[bestI[c[i]]]<hd[i])
      bestI[c[i]] = i;
  }
  vector<ll> bestHD(C+1);
  for(int i=1; i<sz(bestI); i++){
    if(bestI[i] == -1) continue;
    ll cur=0, add = hd[bestI[i]];
    for(int j=i; j<=C; j+=i){
      cur += add;
      bestHD[j] = max(bestHD[j], cur);
    }
  }
  for(int i=1; i<sz(bestHD); i++){
    bestHD[i] = max(bestHD[i], bestHD[i-1]);
  }
  cin >> m;
  for(int i=0; i<m; i++){
    ll D, H;
    cin >> D >> H;
    ll DH = D*H;
    auto it = lower_bound(bestHD.begin(), bestHD.end(), DH+1);
    if(it == bestHD.end()){
      cout << "-1 ";
    }
    else{
      cout << it-bestHD.begin() << " ";
    }
  }
  cout << "\n";
}