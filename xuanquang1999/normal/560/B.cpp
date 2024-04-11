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

int a1, b1, a2, b2, a3, b3;

bool Fit(int a1, int b1, int a2, int b2) {
    return ((a1 >= a2 && b1 >= b2) || (a1 >= b2 && b1 >= a2));
}

bool Check(int a1, int b1, int a2, int b2, int a3, int b3) {
    if (a1 < a2 || b1 < b2) return false;
    return (Fit(a1-a2, b1, a3, b3) || Fit(a1, b1-b2, a3, b3));
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &a1, &b1);
    scanf("%d%d", &a2, &b2);
    scanf("%d%d", &a3, &b3);

    printf((Check(a1, b1, a2, b2, a3, b3) || Check(a1, b1, b2, a2, a3, b3)) ? "YES" : "NO");

    return 0;
}