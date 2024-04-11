#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int Q, H, N;
vector<int> P;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q;
  while(Q--){
    cin >> H >> N;
    P.resize(N);
    for(int i=0; i<N; i++){
      cin >> P[i];
    }
    vector<int> s;
    s.push_back(1);
    for(int i=2; i<N; i++){
      if(P[i-1] == P[i]+1){
        s[sz(s)-1]++;
      }
      else{
        s.push_back(1);
      }
    }
    int cntO = 0;
    for(int x : s){
      if(x%2)
        cntO++;
    }
    if(P[N-1] <= 1 && s[sz(s)-1]%2==1)
      cntO--;
    if(N == 1)
      cntO = 0;
    cout << cntO << "\n";
  }

  return 0;
}