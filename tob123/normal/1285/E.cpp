#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, T;
vector<pii> A, B;
vector<int> L, R;
int C;

void f(vector<int> & r){
  B.clear();
  for(int i=0; i<N; i++){
    B.push_back(make_pair(A[i].first, i));
  }
  sort(B.begin(), B.end());

  C = 0;
  int cnt = 0;
  int x, cur;
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  for(int i=0; i<sz(r); ){
    tie(x, cur) = B[i];
    int j;
    while(Q.size()>0 && Q.top().first < x){
      Q.pop();
    }
    if(sz(Q) == 0){
      cnt = 0;
      C++;
    }
    if(sz(Q) == 1 && cnt > 1){
      r[Q.top().second]++;
    }
    for(j=i; j<sz(r) && B[j].first == x; j++){
      Q.push(make_pair(A[B[j].second].second, B[j].second));
      cnt++;
    }
    i = j;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    A.clear();
    L = vector<int>(N);
    R = vector<int>(N);
    for(int i=0; i<N; i++){
      L[i] = 0;
      int a, b;
      cin >> a >> b;
      A.push_back(make_pair(a, b));
    }
    f(L);
    /*
    for(int i=0; i<N; i++){
      cout << L[i] << " ";
    }
    cout << endl;
    */
    /*
    for(int i=0; i<N; i++){
      A[i].first *= -1;
      A[i].second *= -1;
      swap(A[i].first, A[i].second);
    }
    f(R);
    */
    /*
    for(int i=0; i<N; i++){
      cout << R[i] << " ";
    }
    cout << endl;
    cout << endl;
    */
    int best = 0;
    for(int i=0; i<N; i++){
      //best = max(best, min(L[i], R[i]));
      best = max(best, L[i]);
    }
    cout << min(N-1, best+C) << "\n";
  }

  return 0;
}