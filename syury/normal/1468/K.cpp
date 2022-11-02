//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

inline pii dir(char c){
    if(c == 'L')
        return {-1, 0};
    if(c == 'R')
        return {1, 0};
    if(c == 'D')
        return {0, -1};
    if(c == 'U')
        return {0, 1};
    assert(false);
}

pii endpos(string s, pii obst){
    int x = 0, y = 0;
    for(char c: s){
        int dx, dy;
        tie(dx, dy) = dir(c);
        if(x + dx == obst.X && y + dy == obst.Y)
            continue;
        x += dx;
        y += dy;
    }
    return {x, y};
}

void solve(){
    string s;
    cin >> s;
    int x = 0, y = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int dx, dy;
        tie(dx, dy) = dir(s[i]);
        if(x + dx != 0 || y + dy != 0){
            auto pos = endpos(s, make_pair(x + dx, y + dy));
            if(pos.X == 0 && pos.Y == 0){
                cout << x + dx << ' ' << y + dy << '\n';
                return;
            }
        }
        x += dx;
        y += dy;
    }
    cout << "0 0\n";
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}