#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int n, m, q;
map<int,int> M;
vector<int> A, B, T, X;
vector<pii> Q;

//const int size=32;
const int size=2*1024*1024;
const int offset=size/2-1;
int S[size], U[size];
int par(int x){ return (x-1)/2;}
int left(int x){ return 2*x+1;}
int right(int x) { return 2*x+2;}

void prop_down(int cur){
  S[left(cur)] += U[cur];
  U[left(cur)] += U[cur];
  S[right(cur)] += U[cur];
  U[right(cur)] += U[cur];
  U[cur] = 0;
}

void update(int l, int r, int val, int curl=0, int curr=offset, int cur=0){
/*
  if(curl == 0 && curr == offset){
    cout << "updating " << l << " - " << r << " : " << val << endl;
  }
  */
  if(l > curr || r < curl)
    return;
  if(curl >= l && curr <= r){
    S[cur] += val;
    U[cur] += val;
    return;
  }
  prop_down(cur);
  int m = (curl+curr)/2;
  update(l, r, val, curl, m, left(cur));
  update(l, r, val, m+1, curr, right(cur));
  S[cur] = max(S[left(cur)], S[right(cur)]);
}
int query(int curl=0, int curr=offset, int cur=0){
  if(curl == curr){
    return S[cur] > 0 ? X[curl] : -1;
  }
  prop_down(cur);
  int m = (curl+curr)/2;
  if(S[left(cur)] > 0)
    return query(curl, m, left(cur));
  return query(m+1, curr, right(cur));
}

void printS(){
  int x = 2;
  for(int i=0; i<size-1; i++){
    cout << S[i] << "," << U[i] << " ";
    if(i == x-2){
      cout << "\n";
      x *= 2;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  A.resize(n);
  for(int i=0; i<n; i++){
    cin >> A[i];
    X.push_back(A[i]);
  }
  B.resize(m);
  for(int i=0; i<m; i++){
    cin >> B[i];
    X.push_back(B[i]);
  }
  cin >> q;
  T.resize(q);
  Q.resize(q);
  for(int i=0; i<q; i++){
    cin >> T[i] >> Q[i].first >> Q[i].second;
    X.push_back(Q[i].second);
    Q[i].first--;
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  sort(X.rbegin(), X.rend());
  for(int i=0; i<sz(X); i++){
    M[X[i]] = i;
  }
  for(int i=0; i<n; i++){
    //printS();
    update(M[A[i]], sz(X)-1, 1);
    //printS();
  }
  for(int i=0; i<m; i++){
    update(M[B[i]], sz(X)-1, -1);
  }
  //printS();
  for(int i=0; i<q; i++){
    int ind, val;
    tie(ind, val) = Q[i];
    if(T[i] == 1){
      update(M[A[ind]], sz(X)-1, -1);
      A[ind] = val;
      update(M[A[ind]], sz(X)-1, 1);
    }
    else{
      update(M[B[ind]], sz(X)-1, 1);
      B[ind] = val;
      update(M[B[ind]], sz(X)-1, -1);
    }
    //printS();
    cout << query() << "\n";
  }

  return 0;
}