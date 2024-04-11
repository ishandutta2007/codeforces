#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> ti;

int N, Q;
vector<int> A;
vector<pii> q;
vector<int> P;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  A.resize(N);
  P.resize(N);
  for(int i=0; i<N; i++){
    P[i] = -1;
    cin >> A[i];
    q.push_back({i, A[i]});
  }
  cin >> Q;
  for(int i=0; i<Q; i++){
    int e, p, x;
    cin >> e;
    if(e == 1){
      cin >> p >> x;
      p--;
    }
    else{
      p = -1;
      cin >> x;
    }
    q.push_back({p, x});
  }
  int mx = 0;
  for(int i=Q+N-1; i>=0; i--){
    int p=q[i].first, x=q[i].second;
    if(p == -1){
      mx = max(mx, x);
    }
    else{
      if(P[p] == -1){
        P[p] = max(mx, x);
      }
    }
  }
  for(int i=0; i<N; i++){
    cout << P[i] << " ";
  }
  cout << endl;

  return 0;
}