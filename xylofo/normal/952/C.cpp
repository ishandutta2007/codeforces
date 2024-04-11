
#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
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
    vi v(n);
    rep(i,0,n) cin>>v[i];
    int last = v[0];
    rep(i,0,n) {
      if(abs(last - v[i]) > 1){
        cout << "NO" << endl;
        return 0;
      }
      last = v[i];
    }
    cout << "YES" << endl;
    return 0;
}