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
    set<string> grumpy = {
      "worse",
      "terrible",
      "no way",
      "don't even",
      "go die in a hole",
      "are you serious?",
      "are you serious"
    };
    rep(i,0,10){
      cout << i << endl;
      string s;
      getline(cin,s);
      if(s == "no") continue;
      if(grumpy.count(s)) {
        cout << "grumpy" << endl;
        return 0;
      }
      else {
        cout << "normal" << endl;
        return 0;
      }
    }
    return 0;
}