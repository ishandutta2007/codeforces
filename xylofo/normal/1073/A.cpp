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
    string s;
    cin>>n>>s;
    char c = s[0];
    rep(i,0,n) if(s[i] != c) {
      cout << "YES\n" << s[i-1] << s[i] << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
}