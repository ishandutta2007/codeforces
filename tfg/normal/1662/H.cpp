#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    vector<int> divs;
    auto push = [&](int g){
      for(int i = 1; i * i <= g; i++){
        if(g % i == 0){
          divs.push_back(i);
          divs.push_back(g / i);
        }
      }
    };
    push(gcd(a - 1, b - 1));
    push(gcd(a - 2, b));
    push(gcd(a, b - 2));
    push(gcd(a, gcd(b - 1, a - 2)));
    push(gcd(b, gcd(a - 1, b - 2)));
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
    cout << divs.size();
    for(int v : divs) cout << ' ' << v;
    cout << '\n';
  }
  return 0;
}