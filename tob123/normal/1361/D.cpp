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

const int n = 1e6+10;

double INF = 1e18;
int N, K;
map<pii,vector<int>> M;
vector<double> val[n];
ll X[n], Y[n];
int cnt = 0;
double R;

int solve(double k){
  double res = 0;
  int rcnt = 0;
  double res2 = 0;
  int rcnt2 = 0;
  for(int i=0; i<cnt; i++){
    for(int j=0; j<sz(val[i]); j++){
      double cur = res+val[i][j]-j*k;
      if(cur >= res2){
        res2 = cur;
        rcnt2 = rcnt+j;
      }
    }
    res = res2;
    rcnt = rcnt2;
    res2 = 0;
    rcnt2 = 0;
  }
  R = res;
  return rcnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for(int i=0; i<N;i++){
    cin >> X[i] >> Y[i];
    ll x=X[i], y=Y[i];
    int g = x==0&&y==0 ? 1 : gcd(x, y);
    x /= g;
    y /= g;
    M[{x,y}].push_back(i);
  }
  for(auto p : M){
    auto v = p.second;
    vector<double> v2;
    for(int x : v){
      v2.push_back(sqrt(X[x]*X[x]+Y[x]*Y[x]));
    }
    sort(v2.rbegin(), v2.rend());
    double res=0;
    int mid = min((K+1)/2, sz(v));
    val[cnt].push_back(0);
    for(int i=0; i<mid; i++){
      res += (K-1-2*i)*v2[i];
      val[cnt].push_back(res);
    }
    double suml = 0;
    for(int i=0; i<sz(v)-mid; i++){
      res += (K-1-2*mid)*v2[sz(v)-1-i] - 2*suml;
      suml += v2[sz(v)-1-i];
      val[cnt].push_back(res);
    }
    cnt++;
  }
  /*
  for(int i=0; i<cnt; i++){
    for(double x : val[i]){
      cout << x << " ";
    }
    cout << endl;
  }
  */
  double lo=-INF, hi=INF;
  for(int it=0; it<100; it++){
    double m = (lo+hi)/2;
    int res = solve(m);
    if(res < K){
      hi = m;
    }
    else
      lo = m;
  }
  int r = solve(hi);
  //cout << r << " " << hi << endl;
  cout << fixed << setprecision(10) << R + K*hi << endl;
}