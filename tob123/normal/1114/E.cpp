#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, Q, B;
const int Qmax = 60;
const int INF = 1e9;

vector<int> X, D;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int a, int b){
  std::uniform_int_distribution<int> distribution(a, b);
  return distribution(rng);
}

bool askG(int x){
  cout << "> " << x << endl;
  Q++;
  bool b;
  cin >> b;
  return b;
}

int askV(int x){
  cout << "? " << x << endl;
  Q++;
  cin >> x;
  return x;
}

ll gcd(ll a, ll b){
  if(a == 0)
    return b;
  else
    return gcd(b%a, a);
}

int main(){
  cin >> N;

  if(N <= Qmax){
    vector<int> A(N);
    for(int i=0; i<N; i++){
      cout << "? " << (i+1) << endl;
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    cout << "! " << A[0] << " " << A[1]-A[0] << endl;
    return 0;
  }

  int a=0, b=INF;
  while(a < b){
    int m = (a+b)/2;
    if(askG(m)){
      a = m+1;
    }
    else{
      b = m;
    }
  }
  B = a;
  while(Q < Qmax){
    int x;
    x = rnd(1, N);
    a = askV(x);
    X.push_back(a);
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  sort(X.begin(), X.end());
  for(int i=0; i<X.size(); i++){
    for(int j=i+1; j<X.size(); j++){
      if(X[j]-X[i] > 0)
        D.push_back(X[j]-X[i]);
    }
  }

  if(D.size() == 0){
    cout << "! " << X[0] << " " << 0 << endl;
    return 0;
  }
  sort(D.begin(), D.end());
  D.erase(unique(D.begin(), D.end()), D.end());
  sort(D.begin(), D.end());
  ll res = D[0];
  for(int i=1; i<D.size(); i++){
    res = gcd(res, D[i]);
  }
  /*
  for(int x=D[0]; x>=0; x--){
    bool flag = true;
    for(int v : D){
      if(v%x != 0){
        flag = false;
      }
    }
    if(flag){
      cout << "! " << B-(N-1)*x << " " << x << endl;
      return 0;
    }
  }
  */
  cout << "! " << B-(N-1)*res << " " << res << endl;

  return 0;
}