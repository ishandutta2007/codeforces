#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }

int main(){
  ll i, j;
  set<ll> st;
  vector<ll> s;
  ll n;
  cin >> n;
  ll buf;
  for(i = 0; i < n; i++){
    cin >> buf;
    st.insert(buf);
  }
  if(s.size() > 3)
    cout << -1 << endl;
  //set::iterator itr;
  for(auto itr = st.begin(); itr != st.end(); itr++)
    s.push_back(*itr);
  
  if(s.size() > 3)
    cout << -1 << endl;
  else if(s.size() == 3 && s[1] - s[0] == s[2] - s[1])
    cout << s[2] - s[1] << endl;
  else if(s.size() == 3)
    cout << -1 << endl;
  else if(s.size() == 2 && (s[1] - s[0]) % 2 == 0)
    cout << (s[1] - s[0]) / 2 << endl;
  else if(s.size() == 2)
    cout << s[1] - s[0] << endl;
  else
    cout << 0 << endl;
    

  return 0;
}