#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;

int N;
int mi=INF, ma=-INF, sum;
vector<int> A;
int kirill[3];
int taken[3];

int calcFail(){
  int res = 0;
  for(int i=0; i<3; i++){
    res += min(kirill[i], taken[i]);
  }
  return res;
}

int main(){
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    mi = min(mi, A[i]);
    ma = max(ma, A[i]);
    sum += A[i];
  }
  if(ma-mi != 2){
    cout << N << endl;
    for(int i=0; i<N; i++){
      cout << A[i] << " ";
    }
    cout << endl;
    return 0;
  }
  for(int i=0; i<N; i++){
    kirill[A[i]-mi]++;
  }
  int med = (mi+ma)/2;
  int news = med*N;
  taken[1] = N;
  while(news != sum){
    if(news < sum){
      taken[1]--;
      taken[2]++;
      news++;
    }
    else{
      taken[1]--;
      taken[0]++;
      news--;
    }
  }
  int best = calcFail();
  int bestR[3];
  for(int i=0; i<3; i++)
    bestR[i] = taken[i];
  while(taken[1] >= 2){
    taken[1] -= 2;
    taken[0]++;
    taken[2]++;
    int newF = calcFail();
    if(newF < best){
      best = newF;
    for(int i=0; i<3; i++)
      bestR[i] = taken[i];
    }
  }
  cout << best << endl;
  for(int i=0; i<3; i++){
    for(int j=0; j<bestR[i]; j++){
      cout << mi+i << " ";
    }
  }
  cout << endl;
}