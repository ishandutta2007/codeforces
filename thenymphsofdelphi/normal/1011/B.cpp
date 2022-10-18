#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <pair <int, int> > vii;

const int N = 1e5 + 5, mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n > m){
        cout << 0;
        return 0;
    }
    int a[m];
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a, a + m);
    vi num;
    int t = 1;
    for (int i = 1; i < m; i++){
        if (a[i] == a[i - 1]){
            t++;
        }
        else{
            num.pb(t);
            t = 1;
        }
    }
    num.pb(t);
    sort(num.begin(), num.end());
    for (int ans = 1; ans <= 500; ans++){
        int pos = 0;
        for (int i = 0; i < num.size(); i++){
            pos += num[i] / ans;
        }
        if (pos < n){
            cout << ans - 1;
            return 0;
        }
    }
}