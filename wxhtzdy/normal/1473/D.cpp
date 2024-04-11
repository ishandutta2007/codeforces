#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))

using namespace std;



int n,q;
string s;
int a[200005];
int pref[200005][2];
int suff[200005][2];

void solve(){
    cin >> n >> q >> s;
    ff(i,0,n - 1){
        a[i + 1] = a[i] + (s[i] == '+' ? +1 : -1);
    }
    ff(i,1,n){
        pref[i][0] = pref[i - 1][0];
        pref[i][1] = pref[i - 1][1];
        pref[i][0] = min(pref[i][0], a[i]);
        pref[i][1] = max(pref[i][1], a[i]);
    }
    suff[n][0] = suff[n][1] = suff[n + 1][0] = suff[n + 1][1] = a[n];
    fb(i,n - 1,1){
        suff[i][0] = suff[i + 1][0];
        suff[i][1] = suff[i + 1][1];
        suff[i][0] = min(suff[i][0], a[i]);
        suff[i][1] = max(suff[i][1], a[i]);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int mn = min(pref[l - 1][0], suff[r + 1][0] - (a[r] - a[l - 1]));
        int mx = max(pref[l - 1][1], suff[r + 1][1] - (a[r] - a[l - 1]));
        cout << mx - mn + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}