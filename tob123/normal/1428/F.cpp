#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
void print(tuple<ll,ll,ll> t){
  auto [a,b,c] = t;
  cout << "(" << a << ", " << b << ", " << c << ")  ";
}
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  string S;
  cin >> N >> S;
  deque<tuple<ll,ll,ll>> st;
  ll cnt = 0;
  ll res = 0;
  for(ll i=N-1; i>=0; i--){
    if(S[i] == '0'){
      cnt = 0;
    }
    else{
      cnt++;
    }
    while(sz(st) && get<0>(st[0]) <= cnt)
      st.pop_front();
    //print(st);
    //auto it = upper_bound(st.begin(), st.end(), make_tuple(cnt, -1, -1));
    auto it = st.begin();
    ll curVal = 0;
    if(it == st.end()){
      curVal += cnt*(cnt+1)/2;
      curVal += (N-(i+cnt))*cnt;
    }
    else{
      auto [c, pos, val] = *it;
      curVal += (pos+cnt-(i+cnt))*cnt;
      curVal += val;
    }
    st.emplace_front(cnt, i, curVal);
    //cout << cnt << " " << curVal << endl;
    res += curVal;
  }
  cout << res << "\n";
}