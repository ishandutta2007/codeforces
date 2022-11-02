#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,ll> ti;

const int n = 3e5+10;

int N, M;
ll bal[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int u, v; ll d;
    cin >> u >> v >> d;
    bal[u] -= d; bal[v] += d;
  }
  int m = 0;
  int rp = 1;
  vector<ti> G;
  for(int i=1; i<=N; i++){
    while(bal[i] < 0){
      if(bal[rp] > 0){
        ll x = min(bal[rp], -bal[i]);
        bal[i] += x;
        bal[rp] -= x;
        G.push_back(make_tuple(i, rp, x));
        m++;
      }
      else{
        rp++;
      }
    }
  }
  cout << m << endl;
  for(auto t : G){
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
  }

  return 0;
}