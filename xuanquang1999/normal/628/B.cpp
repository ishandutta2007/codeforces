#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

string s;
int n;
ll ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s;
    n = s.length();
    fto(i, 0, n-2) {
        if (((s[i]-'0')*10+s[i+1]-'0')%4 == 0) ans += i+1;
    }
    fto(i, 0, n-1) {
        if (s[i]%4 == 0) ++ans;
    }

    cout << ans;

    return 0;
}