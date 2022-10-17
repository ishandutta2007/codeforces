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
    //cout << n << endl;
    if(n == 14) {
      cout << R"(0 0
0 1
0 2
0 3
0 4
0 5
0 6
1 0
1 1
1 2
1 3
1 4
1 5
1 6)";
      return 0;
    }
    int len = 2*(n-4)/3;
    if(len%2 == 0) --len;
    if(len < 0) len = 0;
    int cnt = 0;
    vector<vi> v(len+10, vi(3));
    auto put = [&](int x, int y) {
        if(v[x+3][y] == 1) return;
        cout << x << " " << y << "\n";
        assert(v[x+3][y] == 0 && cnt < n);
        v[x+3][y] = 1;
        ++cnt;
    };
    rep(x,0,len) rep(y,0,3) {
      if((x + y)%2 == 0) put(x,y);
    }
    if(n >= 4){
      put(1,0);
      put(1,2);

      put(len-2,0);
      put(len-2,2);
    }
    rep(i,cnt,n) {
      cout << i/2 << " " << 4+(i%2) << endl;
    }

    //rep(j,0,3){ rep(i,0,len+10) cerr << v[i][j] << " "; cerr << endl; }
    return 0;
}