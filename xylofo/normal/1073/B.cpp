#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi v(n), taken(n+1,0);
    rep(i,0,n) cin>>v[n-i-1];
    rep(i,0,n) {
      int a;
      cin>>a;
      if(taken[a]) cout << "0 ";
      else {
        int sz = v.size();
        while(v.back() != a) {
          taken[v.back()] = 1;
          v.pop_back();
        }
        taken[v.back()] = 1;
        v.pop_back();
        cout << sz - v.size() << " ";
      }
    }
    cout << endl;
    return 0;
}