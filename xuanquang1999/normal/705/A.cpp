/*
coded by nghoangphu
*/
/*
Testing
*/
#include <bits/stdc++.h>

#define oo 1000000007
#define debug(a) cout << #a << ": " << a << endl
#define fto(i, x, y) for (int i = (int)(x); i <= (int)(y); ++i)
#define fdto(i, x, y) for (int i = (int)(x); i >= (int)(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define mp make_pair
#define pb push_back
#define scf scanf
#define prf printf
#define maxN 1005

using namespace std;



int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    scf("%d", &n);
    fto(i, 1, n-1) {
        if (i%2) prf("I hate that ");
        else prf("I love that ");
    }
    if (n%2) prf("I hate it");
    else prf("I love it");

    prf("\n");

    return 0;
}