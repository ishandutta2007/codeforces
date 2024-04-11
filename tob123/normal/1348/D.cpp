#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
ll N;
vector<ll> res;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    res.clear();
    N--;
    ll cur = 1;
    while(N > 0){
      if(cur*4 <= N){
        res.push_back(cur);
        cur *= 2;
        N -= cur;
      }
      else if(cur*2 >= N){
        res.push_back(N-cur);
        break;
      }
      else{
        ll x = N-2*cur;
        res.push_back(x/2);
        cur += x/2;
        N -= cur;
      }
    }
    cout << sz(res) << endl;
    for(ll x : res){
      cout << x << " ";
    }
    cout << endl;
  }
}