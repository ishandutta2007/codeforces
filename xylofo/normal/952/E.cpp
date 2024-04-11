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
    int hard = 0, soft = 0;
    rep(i,0,n){
      string s;
      cin>>s>>s;
      if(s == "soft") ++soft;
      else ++hard;
    }
    rep(i,0,100){
      int w = i*i/2;
      int b = i*i-w;
      if(w >= hard && b >= soft) {
        cout << i << endl;
        return 0;
      }
      if(b >= hard && w >= soft) {
        cout << i << endl;
        return 0;
      }
    }
    return 0;
}