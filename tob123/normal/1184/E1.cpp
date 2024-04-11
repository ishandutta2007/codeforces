#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef tuple<int,int,int> pii;

const int n = 1e5+10;

int C[n];
int A, B;
int N, M;

int find(int x){
  if(C[x] != x)
    C[x] = find(C[x]);
  return C[x];
}

void comb(int x, int y){
  C[find(x)] = C[find(y)];
}

int main(){
  cin >> N >> M;
  
  for(int i=0; i<N; i++){
    C[i] = i;
  }
  int a, b, e;
  cin >> A >> B >> e;
  A--; B--;
  if(A > B)
    swap(A, B);
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  for(int i=0; i<M-1; i++){
    cin >> a >> b >> e;
    a--; b--;
    Q.push(make_tuple(e, min(a, b), max(a, b)));
  }
  while(!Q.empty()){
    tie(e, a, b) = Q.top();
    Q.pop();
    if(find(a) == find(b))
      continue;
    if((find(a) == find(A) && find(B) == find(b)) || (find(b) == find(A) && find(B) == find(a))){
      cout << e << endl;
      return 0;
    }
    comb(a, b);
  }
  cout << 1000000000 << endl;

  return 0;
}