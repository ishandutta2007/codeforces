#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const ll INF = 4e18;

int T;
int r, g, b;
vector<ll> R, G, B;

ll best = INF;

ll res(ll a, ll b, ll c){
  return (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);
}

void calc(){
  int gi=0;
  for(int ri=0; ri<sz(R); ri++){
    while(gi < sz(G) && G[gi] < R[ri]) gi++;
    if(gi < sz(G)){
      ll b2 = (R[ri]+G[gi])/2;
      auto it = upper_bound(B.begin(), B.end(), b2);
      if(it != B.end()){
        best = min(best, res(R[ri], G[gi], *it));
      }
      if(it != B.begin()){
        it--;
        best = min(best, res(R[ri], G[gi], *it));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    best = INF;
    cin >> r >> g >> b;
    R.resize(r); G.resize(g); B.resize(b);
    for(int i=0; i<r; i++){
      cin >> R[i];
    }
    sort(R.begin(), R.end());
    for(int i=0; i<g; i++){
      cin >> G[i];
    }
    sort(G.begin(), G.end());
    for(int i=0; i<b; i++){
      cin >> B[i];
    }
    sort(B.begin(), B.end());
    calc();
    swap(R, G);
    calc();
    swap(B, R);
    calc();
    swap(G, R);
    calc();
    swap(B, R);
    calc();
    swap(R, G);
    calc();
    cout << best << "\n";
  }
}