#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <pair <int, int> > vii;

const int N = 1e5 + 5, mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double k;
    int n;
    cin >> n >> k;
    cout << fixed << setprecision(8);
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1){
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        if (b[i] == 1){
            cout << -1;
            return 0;
        }
    }
    long double ans = 0, t;
    for (int i = n - 1; i >= 0; i--){
        t = (k * 1.0) / (b[(i + 1) % n] - 1);
        ans += t;
        k += t;
        //cout << t << endl;
        t = (k * 1.0) / (a[i] - 1);
        ans += t;
        k += t;
        //cout << t << endl;
    }
    cout << ans;
}