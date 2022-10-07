#include <bits/stdc++.h>
#define pb push_back
//#define int long long
#define ll long long
#define F first
#define S second
using namespace std;

const int N = 1000005, MOD = 1e9 + 7;

int cnt[26];

void solve () {
    int n, k;
    cin >> n >> k;k=n/k;
    for (int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        cnt[ch-'a']++;
    }
    for (int i = 0; i < n/k; i++){
        int x = 0;
        while (x < k && x < 25){
            if (cnt[x]){
                cnt[x++]--;
            }
            else
                break;
        }
        cout << (char)(x+'a');
    }
    cout << endl;
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve();
    }
    return 0;
}