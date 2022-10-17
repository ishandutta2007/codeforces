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
    string s;
    cin>>s;
    int cur = 0;
    for(char c:s) {
      while(cur != c){
        cout << "..."<<endl;
        cout << ".X."<<endl;
        cur = (cur + 255)%256;
      }
      cout << ".X."<<endl;
    }
    return 0;
}