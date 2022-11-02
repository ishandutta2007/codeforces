#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define MAXN 300010
#define LSOne(S) (S & (-S))

typedef long long ll;
int T, n;
int A[2][MAXN];
deque<int> B[MAXN];
const int offset = 1024*1024-1;
const int size = 2*offset+1;
int S[size];

int left(int x){
  return 2*x+1;
}
int right(int x){
  return 2*x+2;
}
int par(int x){
  return (x-1)/2;
}

void initSeg(){
  /*
  for(int i=0; i<n; i++){
    S[offset+i] = A[0][i];
  }
  for(int i=offset+n; i<size; i++){
    S[i] = n+1;
  }
  for(int i=offset-1; i>=0; i--){
    S[i] = min(S[left(i)], S[right(i)]);
  }
  */
  for(int i=0; i<size; i++){
    S[i] = n+1;
  }
}

void update(int cur, int v){
  cur += offset;
  S[cur] = v;
  while(cur != 0){
    cur = par(cur);
    S[cur] = min(S[left(cur)], S[right(cur)]);
  }
}

int query(int l, int r, int curl=0, int curr=offset, int cur=0){
  if(l<=curl && r>=curr){
    return S[cur];
  }
  if(l > curr || r < curl)
    return n+1;
  int m = (curl+curr)/2;
  return min(query(l, r, curl, m, left(cur)), query(l, r, m+1, curr, right(cur)));
}

int main(){
  cin >> T;
  initSeg();
  while(T--){
    cin >> n;
    for(int j=0; j<2; j++){
      for(int i=0; i<n; i++){
        cin >> A[j][i];
        A[j][i]--;
      }
    }
    for(int i=0; i<n; i++){
      B[i].clear();
      update(i, A[0][i]);
    }
    for(int i=0; i<n; i++){
      B[A[0][i]].push_back(i);
    }
    for(int i=0; i<n; i++){
      int v = A[1][i];
      if(sz(B[v]) == 0){
        cout << "NO\n";
        goto END;
      }
      int ind = B[v].front();
      B[v].pop_front();
      //cout << v << " " << ind << " -> " << query(0, ind-1) << endl;
      if(query(0, ind-1) < v){
        cout << "NO\n";
        goto END;
      }
      update(ind, n+1);
    }
    cout << "YES\n";

END:
    for(int i=0; i<n; i++){
      update(i, n+1);
    }
  }

  return 0;
}