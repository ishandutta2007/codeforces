#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define fi first
#define se second

pair <int, int> cal(pair <int, int> a){
    if (a.fi == 0 || a.se == 0 || (a.fi < 2 * a.se && a.se < 2 * a.fi)){
        return a;
    }
    if (a.fi >= 2 * a.se){
        a.fi %= 2 * a.se;
    }
    else{
        a.se %= 2 * a.fi;
    }
    return cal(a);
}

signed main(){
    int n, m;
    cin >> n >> m;
    pair <int, int> ans = mp(n, m);
    ans = cal(ans);
    cout << ans.fi << ' ' << ans.se;
}