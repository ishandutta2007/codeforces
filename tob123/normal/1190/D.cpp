#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sz(x) ((ll) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<pii> A;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
T S;
//cout<< X.order_of_key(7)<<endl;
//cout<< *X.find_by_order(6)<<endl;

int main(){
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i].second >> A[i].first;
    A[i].first *= -1;
  }
  sort(A.begin(), A.end());
  ll res = 0;
  for(int i=0; i<N; ){
    int l=i;
    vector<ll> cur;
    while(i<N && A[i].first == A[l].first){
      S.insert(A[i].second);
      i++;
    }
    for(int j=l; j<i; j++){
      cur.push_back(S.order_of_key(A[j].second));
    }
    cur.push_back(sz(S));
    ll curRes = sz(S)*(sz(S)+1)/2;
    ll last = -1;
    //cout << curRes << endl;
    for(ll x : cur){
      //cout << x << " ";
      ll k = x-last-1;
      last = x;
      curRes -= k * (k+1) / 2;
    }
    //cout << endl;
    //cout << curRes << endl;
    res += curRes;
  }
  cout << res << endl;

  return 0;
}