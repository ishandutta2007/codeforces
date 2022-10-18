using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 55

int a[3][maxN], b[maxN], n, t[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, 2)
        fto(j, 1, n-1) scanf("%d", &a[i][j]);
    fto(i, 1, n) scanf("%d", &b[i]);

    fto(i, 1, n) {
        fto(j, 1, i-1) t[i]+=a[1][j];
        t[i]+=b[i];
        fto(j, i, n-1) t[i]+=a[2][j];
    }

    sort(t+1, t+1+n);

    cout << t[1]+t[2];


    return 0;
}