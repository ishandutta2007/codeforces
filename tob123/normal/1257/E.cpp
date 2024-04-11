#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
int K[3];
vector<int> B;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int i=0; i<3; i++){
    cin >> K[i];
    N += K[i];
  }
  B.resize(N);
  for(int i=0; i<3; i++){
    //A[i].resize(K[i]);
    for(int j=0; j<K[i]; j++){
      int a;
      cin >> a;
      a--;
      B[a] = i;
    }
    //sort(A[i].begin(), A[i].end());
  }
  int bst = min(N-K[0], min(N-K[1], N-K[2]));
  vector<pii> x;
  x.push_back(make_pair(-1, N));
  int s = K[1];
  for(int i=0; i<N; i++){
    if(B[i] == 1){
      s--;
    }
    else if(B[i] == 2){
      s++;
    }
    while(s <= x.back().first){
      x.pop_back();
    }
    x.push_back(make_pair(s, i+1));
  }
  bst = min(bst, K[0]+x[1].first);
  int ri = 0;
  int r = 0;
  int cnt = K[0];
  for(int l=0; l<N; l++){
    if(B[l] == 0){
      cnt--;
    }
    else if(B[l] == 1){
      cnt++;
    }
    while(l >= r){
      ri++;
      r = x[ri].second;
    }
    bst = min(bst, cnt+x[ri].first);
  }
  cout << bst << endl;

  return 0;
}