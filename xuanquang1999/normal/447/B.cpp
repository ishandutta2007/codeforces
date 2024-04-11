using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

int n, k, cnt[26];
ll ans, maxC, cntI;
string s;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    getline(cin, s); n = s.length();
    scanf("%d", &k);
    fto(i, 0, 25) scanf("%d", &cnt[i]), maxC = max(maxC, (ll)cnt[i]);

    fto(i, 0, n-1) ans+=cnt[s[i]-97]*(i+1);
    fto(i, n+1, n+k) cntI+=i;
    ans+=cntI*maxC;

    cout << ans;


    return 0;
}