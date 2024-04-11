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
const ll MOD = 998244353;

int N, M, K;
ll tot[2];
ll cnt[2][n][2];
ll mixed[2];
ll det[2];
ll pw[n];

void u(int ind, int x, int sign){
  if(cnt[ind][x][0]>0 && cnt[ind][x][1]>0){
    (det[ind] += sign+MOD) %= MOD;
  }
  else if(cnt[ind][x][0]>0 || cnt[ind][x][1]>0){
    (mixed[ind] += sign+MOD) %= MOD;
  }
}

void upd(int ind, int x, int v, int sign){
  tot[(x+v)%2] += sign;
  u(ind, x, -1);
  (cnt[ind][x][v] += MOD+sign)%=MOD;
  u(ind, x, 1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pw[0] = 1;
  for(int i=1; i<n; i++){
    pw[i] = (pw[i-1]*2)%MOD;
  }
  cin >> N >> M >> K;
  map<pii, int> lst;
  for(int i=0; i<K; i++){
    int x, y, t;
    cin >> x >> y >> t;
    int sign = 1;
    if(t == -1){
      if(lst.count(make_pair(x,y)) != 0){
        t = lst[make_pair(x,y)];
        lst.erase(make_pair(x,y));
        sign = -1;
      }
    }
    else{
      if(lst.count(make_pair(x,y))){
        auto z = lst[make_pair(x,y)];
        upd(0, x, (y+z)%2, -1);
        upd(1, y, (x+z)%2, -1);
      }
      lst[make_pair(x,y)] = t;
    }
    if(t != -1){
      upd(0, x, (y+t)%2, sign);
      upd(1, y, (x+t)%2, sign);
    }
    ll res;
    if(det[0] && det[1]){
      res = 0;
    }
    else if(det[0]){
      res = pw[M-mixed[1]];
    }
    else if(det[1]){
      res = pw[N-mixed[0]];
    }
    else{
      //cout << N << " " << M << " " << mixed[0] << " " << mixed[1] << endl;
      res = (pw[N-mixed[0]]+pw[M-mixed[1]])%MOD;
      if(tot[0] && tot[1]){
      }
      else if(tot[0] || tot[1]){
        res = (res+MOD-1)%MOD;
      }
      else{
        res = (res+MOD-2)%MOD;
      }
    }
    cout << res << "\n";
  }
}