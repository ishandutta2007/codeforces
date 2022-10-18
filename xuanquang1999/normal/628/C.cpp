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

string s, ans;
int n, k, cnt;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    cin >> s;

    fto(i, 0, n-1) cnt += max(s[i]-'a', 25-(s[i]-'a'));
    if (cnt < k) puts("-1");
    else {
        fto(i, 0, n-1) {
            char c1 = s[i]-min(s[i]-'a', k);
            char c2 = s[i]+min(25-(s[i]-'a'), k);
            char c = (abs(s[i]-c1) > abs(s[i]-c2)) ? c1 : c2;
            printf("%c", c);
            k -= abs(s[i]-c);
        }
    }

    return 0;
}