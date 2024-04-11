#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, M;
vector<int> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  if(M == 0 && N <= 2){
    for(int i=1; i<=N; i++)
      cout << i << " ";
    cout << endl;
    return 0;
  }
  int cur = 1;
  while(M >= (cur-1)/2){
    A.push_back(cur);
    M -= (cur-1)/2;
    cur++;
  }
  //cout << cur << endl;
  if(M > 0 && cur > N || cur > N+1){
    cout << -1 << endl;
  }
  else{
    int cnt = cur-1;
    if(M != 0){
      cnt++;
      int lev = (cur-1)/2;
      while(lev > M){
        cur += 2;
        lev--;
      }
      A.push_back(cur);
    }
    int b = A[sz(A)-1]+1;
    cur = 1e9-1;
    while(cnt < N){
      A.push_back(cur);
      cnt++;
      cur -= b;
    }
    sort(A.begin(), A.end());
    for(int x : A){
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}