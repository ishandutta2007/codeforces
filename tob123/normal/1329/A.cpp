#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

ll N, M;
ll L[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  ll sum = 0;
  for(int i=0; i<M; i++){
    cin >> L[i];
    sum += L[i];
  }
  bool pos = true;
  for(int i=0; i<M; i++){
    if(i+L[i] > N)
      pos = false;
  }
  if(!pos || sum < N || L[M-1]+M-1 > N){
    cout << -1 << endl;
  }
  else{
    int curI = 1;
    for(int i=0; i<M; i++){
      if(curI+sum <= N){
        curI = N-sum+1;
      }
      sum -= L[i];
      cout << curI << " ";
      curI++;
    }
    cout << "\n";
  }

  return 0;
}