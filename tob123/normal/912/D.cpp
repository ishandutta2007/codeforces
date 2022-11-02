#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<ll, ll>> t;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int,int> & v) const {
    return v.first*31+v.second;
  }
};

ll N, M, R, K;

vector<pair<int,int>> occ;
priority_queue<t> PQ;
unordered_set<pair<int,int>, pair_hash> HS;


ll getNumb(ll i1, ll i2){
  ll r = min(i2, M-R);
  ll l = max(0ll, i2-R+1);
  ll o = max(0ll, i1-R+1);
  ll u = min(i1, N-R);

  ll h = max(0ll, r-l+1);
  ll v = max(0ll, u-o+1);
  return v*h;
}

void ins(ll i1, ll i2){
  if(i1 < 0 || i2 < 0 || i1 >= N || i2 >= M)
    return;

  if(HS.count(make_pair(i1, i2)) == 0){
    PQ.push(make_pair(getNumb(i1, i2), make_pair(i1, i2)));
    HS.insert(make_pair(i1, i2));
  }
}

void insertMax(){
  int x = N/2;
  int y = M/2;
  ins(x, y);
}

long double fishes(){
  insertMax();
  ll f = 0;
  for(int i=0; i<K; i++){
    auto p = PQ.top();
    PQ.pop();
    ll i1 = p.second.first;
    ll i2 = p.second.second;

    f += p.first;

    ins(i1-1, i2);
    ins(i1+1, i2);
    ins(i1, i2-1);
    ins(i1, i2+1);
  }

  return (long double) f;
}

void test(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cout << i << ", " << j << ": " << getNumb(i, j) << endl;
    }
  }
}

int main(){
  cin >> N >> M >> R >> K;

  long double f = fishes();
  //cout << f << endl;
  //test();
  cout << fixed << setprecision(10) << f / ((N-R+1)*(M-R+1)) << endl;

  return 0;
}