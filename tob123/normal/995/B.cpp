#include <bits/stdc++.h>
using namespace std;

#define lsb(x) ((x) & -(x))

const int n = 101;

int N;
vector<int> A[n];
int to[2*n+2];
int F[2*n+1];

void printF(){
  for(int i=0; i<2*N; i++){
    cout << F[i] << " ";
  }
  cout << endl;
}

int query(int a){
  int sum = 0;
  while(a > 0){
    sum += F[a];
    a -= lsb(a);
  }
  return sum;
}

void update(int cur, int add){
  while(cur <= 2*N){
    F[cur] += add;
    cur += lsb(cur);
  }
}

void construct(){
  for(int i=1; i<=2*N; i++){
    update(i, 1);
  }
  //printF();
}

int main(){
  cin >> N;
  for(int i=0; i<2*N; i++){
    int x;
    cin >> x;
    x--;
    A[x].push_back(i);
  }
  for(int i=0; i<N; i++){
    to[min(A[i][0], A[i][1])] = max(A[i][0], A[i][1]);
  }
  /*
  for(int i=0; i<2*N; i++){
    cout << i << " -> " << to[i] << endl;
  }
  */

  construct();
  int cnt = 0;
  for(int i=0; i<2*N; i++){
    if(to[i] == 0)
      continue;
    cnt += query(to[i]) - 1;
    update(to[i]+1, -1);
    update(i+1, -1);
    //cout << i << ", " << to[i] << endl;
    //printF();
  }

  cout << cnt << endl;

  return 0;
}