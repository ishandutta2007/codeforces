#include <bits/stdc++.h>
using namespace std;

# define MAXN 2020
int n , p [ MAXN ] , s [ MAXN ];
void init () {
  for ( int i = 0; i < n ; i ++)
    p [ i ] = i , s [ i ] = 1;
}
int findSet ( int i ) {
  return p [ i ] == i ? i : ( p [ i ] = findSet ( p [ i ]) ) ;
}
bool inSameSet ( int i , int j ) {
  return findSet ( i ) == findSet ( j ) ;
}
int getSizeOfSet ( int i ) {
  return s [ findSet ( i ) ];
}
void unionSet ( int i , int j ) {
  i = findSet ( i ) , j = findSet ( j ) ;
  if ( i != j ) {
    if ( s [ i ] < s [ j ])
      swap (i , j ) ;
    s [ i ] += s [ j ];
    p[j] = i;
  }
}

int N, M;
char A[MAXN][MAXN];
int D[MAXN];
vector<int> G[MAXN];
int in[MAXN];

int main(){
  cin >> N >> M;
  n = N+M;
  init();
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> A[i][j];
      if(A[i][j] == '='){
        unionSet(i, N+j);
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(A[i][j] == '>'){
        G[findSet(N+j)].push_back(findSet(i));
      }
      else if(A[i][j] == '<'){
        G[findSet(i)].push_back(findSet(N+j));
      }
    }
  }

  for(int i=0; i<N+M; i++){
    for(int x : G[i]){
      in[x]++;
    }
  }
  
  queue<int> Q;
  for(int i=0; i<N+M; i++){
    if(in[i] == 0){
      Q.push(i);
    }
  }

  int cnt = 0;

  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    cnt++;
    for(int x : G[cur]){
      D[x] = max(D[x], D[cur]+1);
      in[x]--;
      if(in[x] == 0){
        Q.push(x);
      }
    }
  }

  if(cnt != N+M){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for(int i=0; i<N; i++){
    cout << D[findSet(i)]+1 << " ";
  }
  cout << endl;
  for(int i=0; i<M; i++){
    cout << D[findSet(N+i)]+1 << " ";
  }
  cout << endl;

  return 0;
}