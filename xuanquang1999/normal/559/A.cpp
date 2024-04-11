using namespace std;
#include <bits/stdc++.h>
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
#define maxN 100005

ll a1, a2, a3, a4, a5, a6, p, t1, t2, t3;

ll CNT(ll n) {
    ll sum = 0;
    fto(i, 1, n) sum+=2*i-1;
    return sum;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

    p = a1+a2+a3;
    t1 = a1; t2 = a3; t3 = a5;

    cout << (CNT(p)-CNT(t1)-CNT(t2)-CNT(t3));

    return 0;
}