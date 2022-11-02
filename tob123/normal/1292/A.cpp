#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, Q;
int con = 0;
int A[3][n];

int cnt(int x){
  int c1 = (A[1][x-1] && A[1][x]) || (A[2][x-1] && A[2][x]);
  int c2 = (A[1][x+1] && A[1][x]) || (A[2][x+1] && A[2][x]);
  return c1 + c2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  for(int i=0; i<=N+1; i++){
    A[1][i] = true;
    A[2][i] = true;
  }
  for(int i=0; i<Q; i++){
    int y, x;
    cin >> y >> x;
    int c = cnt(x);
    A[y][x] = !A[y][x];
    int c2 = cnt(x);
    con = con + c - c2;
    if(con == 0){
      cout << "Yes\n";
    }
    else{
      cout << "No\n";
    }
  }

  return 0;
}