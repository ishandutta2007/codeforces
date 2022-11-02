#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, T;
vector<int> A, P;
bool vis[n];
int cnt[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    P.resize(N);
    A.resize(N);
    priority_queue<pii> Q;
    set<int> X;
    for(int i=0; i<N; i++){
      vis[i] = false;
      cin >> P[i];
      P[i]--;
      A[P[i]] = i;
      cnt[i] = 1;
      Q.push(make_pair(1, i));
      X.insert(i);
    }
    bool pos = true;
    for(int i=0; i<N; i++){
      while(vis[Q.top().second])
        Q.pop();
      if(cnt[i] != Q.top().first){
        pos = false;
        break;
      }
      vis[i] = true;
      X.erase(A[i]);
      auto it = X.upper_bound(A[i]);
      if(it != X.end()){
        cnt[P[*it]]++;
        Q.push(make_pair(cnt[P[*it]], P[*it]));
      }
    }
    if(pos){
      cout << "Yes\n";
    }
    else{
      cout << "No\n";
    }
  }
}