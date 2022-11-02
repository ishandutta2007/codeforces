#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e6+10;

int N;
ll A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int x;
  for(int i=1; i<=N; i++){
    cin >> A[i];
    if(A[i] == -1){
      x = i;
    }
  }
  int k=(int) (log2(N)+0.5);
  priority_queue<ll, vector<ll>, greater<ll>> Q;
  ll res = 0;
  int ind = N;
  Q.push(A[N]);
  while(x < ind){
    res += Q.top();
    Q.pop();
    for(int i=ind-1; i>=ind/2; i--){
      if(i != x)
        Q.push(A[i]);
    }
    ind /= 2;
  }
  cout << res << endl;

  return 0;
}