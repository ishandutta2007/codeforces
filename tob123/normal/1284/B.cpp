#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N;
int L[n];
int u[n], d[n];
int cnt;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int ind = 0;
  cnt = N;
  ll sum = 0;
  for(int i=0; i<N; i++){
    u[ind] = -1;
    d[ind] = 1e6+10;
    cin >> L[i];
    bool works = false;
    for(int j=0; j<L[i]; j++){
      int x;
      cin >> x;
      if(x > d[ind]){
        works = true;
      }
      d[ind] = min(d[ind], x);
      u[ind] = max(u[ind], x);
    }
    if(works){
      sum += 2*cnt-1;
      cnt--;
    }
    else{
      ind++;
    }
  }
  sort(d, d+ind);
  sort(u, u+ind);
  int ri = 0;
  for(int i=0; i<ind; i++){
    while(ri < ind && u[ri] <= d[i]) ri++;
    //cout << i << " " << ri << endl;
    sum += ind-ri;
  }
  cout << sum << endl;

  return 0;
}