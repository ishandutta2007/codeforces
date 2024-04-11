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
    ll a, b;
    cin>>a>>b;
    ll l = 0, r = 200000;
    while(l+1 != r){
      ll q = (l+r)/2;
      // use numbers [1,q)
      if(q * (q-1) <= 2*(a+b)) l = q;
      else r = q;
    }
    vi A, B;
    for(int q = l-1; q > 0; --q) {
      if(a >= q) {
        a -= q;
        A.eb(q);
      }
      else B.eb(q);
    }
    cout << A.size() << endl;
    for(int x:A) cout << x << " ";
    cout << endl << B.size() << endl;
    for(int x:B) cout << x << " ";
    cout << endl;
    return 0;
}