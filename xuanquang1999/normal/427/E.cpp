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
#define maxN 1000005
#define oo 1000000007

int n, m, x[maxN];
ll fl[maxN], fr[maxN], ans;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &x[i]);

    fl[1] = 0;
    fto(i, 2, n) {
        fl[i] = fl[i-1]+(ll)(x[i]-x[i-1])*(ll)((1+(i-2)/m)*2);
    }
    fr[n] = 0;
    fdto(i, n-1, 1) {
        fr[i] = fr[i+1]+(ll)(x[i+1]-x[i])*(ll)((1+(n-i-1)/m)*2);
    }
//    fto(i, 1, n) cout << fl[i] << " ";
//    cout << endl;
//    fto(i, 1, n) cout << fr[i] << " ";
//    cout << endl;

    ans = 1000000000000000007LL;
    fto(i, 1, n) ans = min(ans, fl[i]+fr[i]);
    cout << ans;

    return 0;
}