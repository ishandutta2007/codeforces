#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 1e5 + 5;

string s, t;
int n, ans;
int a[N][26], b[26], c[26];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    n = s.length();
    s = ' ' + s;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 26; j++){
            a[i][j] = a[i - 1][j];
        }
        if (s[i] >= 'a' && s[i] <= 'z'){
            a[i][s[i] - 'a']++;
        }
    }
    for (int i = 0; i < (int)t.length(); i++){
        b[t[i] - 'a']++;
    }
    for (int i = (int)t.length(); i <= n; i++){
        bool ck = 1;
        for (int j = 0; j < 26; j++){
            if (a[i][j] - a[i - t.length()][j] > b[j]){
                ck = 0;
                break;
            }
        }
        if (ck) ans++;
    }
    cout << ans;
}