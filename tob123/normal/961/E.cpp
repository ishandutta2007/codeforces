#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int N;
ll A[200001];

const int size = 1024*512;
int offset = size/2 - 1;
ll S[size];

int parent(int x){
  return (x-1)/2;
}
int left(int x){
  return 2*x+1;
}
int right(int x){
  return 2*x+2;
}

void update(ll r, int curl=0, int curr=offset, int cur=0){
  if(curr <= r){
    S[cur]++;
    return;
  }
  if(curl > r){
    return;
  }
  int m = (curl+curr)/2;
  update(r, curl, m, left(cur));
  update(r, m+1, curr, right(cur));
}

ll query(int x){
  x += offset;
  ll sum = S[0];
  while(x != 0){
    sum += S[x];
    x = parent(x);
  }
  return sum;
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
    A[i]--;
  }

  vector<pii> A2;
  for(ll i=0; i<N; i++){
    A2.push_back(make_pair(min(i-1, A[i]), i));
  }
  sort(A2.begin(), A2.end());

  ll res = 0;
  int cur = 0;
  for(int i=0; i<N; i++){
    while(cur <= A2[i].first){
      //cout << i << endl;
      update(A[cur]);
      cur++;
    }
    //cout << A2[i].first << ", " << A2[i].second << endl;
    res += query(A2[i].second);
  }

  cout << res << endl;

  return 0;
}