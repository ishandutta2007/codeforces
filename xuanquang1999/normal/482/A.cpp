#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); ++i)
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

int n, k, a[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    if (k == 1) {
        fto(i, 1, n) printf("%d ", i);
    }
    else {
        fto(i, 1, k+1) {
            if (i%2 == 1) printf("%d ", k+1-i/2);
            else printf("%d ", i/2);
        }
        fto(i, k+2, n) printf("%d ", i);
    }

    return 0;
}