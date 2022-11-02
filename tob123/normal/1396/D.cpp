#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int n = 1e4+10;
const ll MOD = 1e9+7;

ll N, K, L;
multiset<int> C[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K >> L;
  vector<tuple<int,int,int>> E;
  E.emplace_back(-1, -1, -1);
  for(int i=0; i<N; i++){
    int x, y, c;
    cin >> x >> y >> c;
    c--;
    E.emplace_back(x, y, c);
  }
  E.emplace_back(L, -1, -1);
  sort(E.begin(), E.end());
  ll res = 0;
  for(int ei=1; ei<sz(E)-1; ei++){
    //cout << "start " << get<0>(E[ei]) << ", " << get<1>(E[ei]) << endl;
    for(int i=0; i<K; i++){
      C[i].clear();
      C[i].insert(-1);
      C[i].insert(L);
    }
    vector<pii> A;
    for(int i=1; i<=ei; i++){
      auto [x, y, c] = E[i];
      C[c].insert(y);
      A.emplace_back(y, c);
    }
    sort(A.begin(), A.end());
    int cur = -1;
    for(int i=0; i<K; i++)
      cur = max(cur, *(++(C[i].begin())));
    ll curPos = 0;
    set<pii> S;
    S.insert({-1, 0});
    for(int ai=0; ai<sz(A); ai++){
      auto [y, c] = A[ai];
      if(ai == 0 || y != A[ai-1].first){
        (curPos += ((ll)(L-cur)) * (y-(--(S.end()))->first)) %= MOD;
        S.insert({y, cur});
      }
      cur = max(cur, *(C[c].upper_bound(y)));
    }
    S.insert({L, L});
    //cout << "curPos start: " << curPos << endl;
    for(int i=1; i<=ei; i++){
      auto [x, y, c] = E[i];

      ll wl = (get<0>(E[i])-get<0>(E[i-1]));
      ll wr = (get<0>(E[ei+1])-get<0>(E[ei]));
      /*
      cout << wl << " * " << wr << " " << curPos << endl;
      cout << "S: ";
      for(auto p : S){
        cout << "(" << p.first << "," << p.second << "); ";
      }
      cout << endl;
      */
      (res += curPos * wl % MOD * wr) %= MOD;

      //cout << "del " << x << " " << y << endl;
      int yPrev = *(--(C[c].lower_bound(y)));
      auto it = --(S.upper_bound(make_pair(yPrev, L+5)));
      if(it -> first != yPrev){
        S.insert(make_pair(yPrev, (++it)->second));
        it = S.upper_bound(make_pair(yPrev, L+5));
      }
      else
        it++;
      int newTo = *(++(C[c].lower_bound(y)));
      //cout << "to -> " << newTo << endl;
      int lst = yPrev;
      while(it->second < newTo){
        (curPos += MOD - ((ll)(it->first - lst)) * (L - it->second) % MOD) %= MOD;
        lst = it->first;
        auto it2 = it++;
        S.erase(it2);
      }
      if(lst != yPrev){
        S.insert({lst, newTo});
        (curPos += ((ll)(lst-yPrev)) * (L-newTo)) %= MOD;
      }
      C[c].erase(C[c].find(y));
    }
  }
  cout << res << endl;
}