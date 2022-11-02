#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<int> A;

int f(int l, int r, int ind){
  if(ind == -1)
    return 0;
  if(l > r)
    return 0;
  int m;
  for(m=l; m<=r && (A[m] & (1<<ind)) == 0; m++) ;
  //cout << l << " " << r << " " << ind << " -> " << m << endl;
  int r1 = f(l, m-1, ind-1);
  int r2 = f(m, r, ind-1);
  if(m == l)
    return r2;
  if(m == r+1)
    return r1;
  return min(r1, r2) + (1<<ind);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int res = f(0, N-1, 29);
  cout << res << endl;
  
  return 0;
}