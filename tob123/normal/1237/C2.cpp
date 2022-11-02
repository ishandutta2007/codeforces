#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int,int> ti;

const int n = 1e5;

int N;
deque<ti> A;
int nxt[n], pre[n];

int cntEq(ti a, ti b){
  if(get<0>(a) != get<0>(b)){
    return 0;
  }
  if(get<1>(a) != get<1>(b)){
    return 1;
  }
  return 2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    int x, y, z;
    cin >> x >> y >> z;
    A.push_back(make_tuple(x, y, z, i+1));
  }
  sort(A.begin(), A.end());
  A.push_front(make_tuple(-1, -1, -1, -1));
  nxt[N] = -1;
  pre[0] = -1;
  for(int i=0; i<N; i++){
    nxt[i] = i+1;
    pre[i+1] = i;
  }
  for(int e=2; e>=0; e--){
    int cur = nxt[0];
    while(cur != -1 && nxt[cur] != -1){
      if(cntEq(A[cur], A[nxt[cur]]) == e){
        cout << get<3>(A[cur]) << " " << get<3>(A[nxt[cur]]) << "\n";
        int n = nxt[nxt[cur]];
        int p = pre[cur];
        nxt[p] = n;
        if(n != -1)
          pre[n] = p;
        cur = n;
      }
      else{
        cur = nxt[cur];
      }
    }
  }

  return 0;
}