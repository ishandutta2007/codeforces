#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, M;
vector<vector<int>> A;
int R[1<<10];

void printB(int x){
  bitset<8> z(x);
  cout << z;
}

pair<int,int> res(int m){
  int a=0, b=0;
  for(int i=0; i<1<<M; i++)
    R[i] = 0;
  //cout << m << ": ";
  for(int i=0; i<N; i++){
    int x = 0;
    for(int j=0; j<M; j++){
      x <<= 1;
      x += A[i][j] >= m;
    }
    //cout << i+1 << " ";
    //printB(x);
    //cout << ", ";
    R[x] = i+1;
  }
  //cout << endl;
  for(int i=0; i<1<<M; i++){
    if(R[i]){
      for(int j=i; j>0; j=(j-1)&i){
        R[j] = R[i];
      }
      R[0] = R[i];
    }
  }
  /*
  for(int i=0; i<1<<M; i++){
    cout << R[i] << " ";
  }
  cout << endl;
  */
  for(int i=0; i<1<<M; i++){
    if(R[i]>0 && R[((1<<M)-1)^i]>0){
      a = R[i]; b = R[((1<<M)-1)^i];
    }
  }
  return make_pair(a,b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  A.resize(N);
  for(int i=0; i<N; i++){
    A[i].resize(M);
    for(int j=0; j<M; j++){
      cin >> A[i][j];
    }
  }
  int l=0, r=1e9+10;
  while(l < r){
    int m = (l+r+1)/2;
    auto p = res(m);
    //cout << m << ": " << p.first << " " << p.second << endl;
    bool pos = p.first != 0;
    if(pos){
      l = m;
    }
    else{
      r = m-1;
    }
  }
  auto p = res(l);
  cout << p.first << " " << p.second << endl;

  return 0;
}