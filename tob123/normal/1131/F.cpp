#include <bits/stdc++.h>
using namespace std;

# define MAXN 150010
int n , p [ MAXN ] , s [ MAXN ];

int N;
vector<int> G[MAXN];
vector<int> R;
int D;


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
/*
int getSizeOfSet ( int i ) {
  return s [ findSet ( i ) ];
}
*/
void unionSet ( int i , int j ) {
  i = findSet ( i ) , j = findSet ( j ) ;
  if ( i != j ) {
    if ( s [ i ] < s [ j ])
      swap (i , j ) ;
    s [ i ] += s [ j ];
    G[i].push_back(j);
    p[j] = i;
  }
}

void dfs(int cur){
  // R[cur] = ++D;
  R[D++] = cur+1;
  for(int x : G[cur]){
    dfs(x);
  }
}

int main(){
  cin >> N;
  n = N;
  init();
  R.resize(N);
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    unionSet(a, b);
  }

  dfs(findSet(0));

  for(int i=0; i<N; i++){
    cout << R[i] << " ";
  }
  cout << endl;

  return 0;
}