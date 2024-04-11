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
    int m, n, ans;
    cin >> m >> n;
    vi loop;
    for (int i = 0; i < n; i++){
        cout << 1 << endl << flush;
        cin >> ans;
        if (ans == 0 || ans == -2){
            exit(0);
        }
        if (ans == -1){
            loop.pb(0);
        }
        else{
            loop.pb(1);
        }
    }
    int l = 2, r = m, idx = 0, mid;
    while (ans != 0 && ans != -2){
        mid = (l + r) / 2;
        cout << mid << endl << flush;
        cin >> ans;
        if (ans == 0 || ans == -2){
            continue;
        }
        if (loop[idx] == 0){
            ans = -ans;
        }
        idx = (idx + 1) % loop.size();
        if (ans == -1){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    exit(0);
}