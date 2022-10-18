#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

bool cmp1(pair <int, int> a, pair <int, int> b){
    int x = a.fi - a.se, y = b.fi - b.se;
    if (x < y){
        return 1;
    }
    return 0;
}

signed main(){
    int n, k;
    cin >> n >> k;
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].fi;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i].se;
    }
    sort(a.begin(), a.end(), cmp1);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (i < k){
            ans += a[i].fi;
        }
        else{
            if (a[i].fi < a[i].se){
                ans += a[i].fi;
                continue;
            }
            ans += a[i].se;
        }
    }
    cout << ans;
}