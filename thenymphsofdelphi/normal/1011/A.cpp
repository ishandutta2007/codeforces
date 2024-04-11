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
    int n, k, ans = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int cnt = 0;
    char pre = 'a' - 3;
    for (int i = 0; i < s.length(); i++){
        if (s[i] - pre >= 2){
            cnt++;
            pre = s[i];
            ans += (s[i] - 'a') + 1;
        }
        if (cnt == k){
            break;
        }
    }
    if (cnt < k){
        cout << -1;
        return 0;
    }
    cout << ans;
}