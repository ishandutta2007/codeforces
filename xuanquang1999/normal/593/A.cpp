#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define forrit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mapii map<int, int>
#define maxN 100005
#define oo 1000000007

int nS, cnt[729];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nS);
    fto(iS, 1, nS) {
        char s[1000];
        cin >> s;

        int n = strlen(s), cntC = 0;
        bool choose[256];
        memset(choose, false, sizeof(choose));
        fto(i, 0, n-1)
            if (!choose[s[i]]) {
                choose[s[i]] = true;
                ++cntC;
                if (cntC == 3) break;
            }
        if (cntC == 3) continue;

        int hV = 0;
        fto(i, 'a', 'z') {
            if (choose[i]) hV = hV*27+(i-'a')+1;
        }
        cnt[hV]+=n;
    }

    int ans = 0;
    fto(i, 1, 26)
        fto(j, i+1, 26) cnt[i*27+j] += cnt[i]+cnt[j];
    fto(j, 27, 728) ans = max(ans, cnt[j]);

    cout << ans;

    return 0;
}