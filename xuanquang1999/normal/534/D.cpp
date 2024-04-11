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
#define maxN 200005
#define mod 1000000009

int n, a[maxN], l[maxN], k;
vector<int> hs[maxN], ans;

bool Check(int x) {
    if (hs[x].size()-l[x]) {
        ans.pb(hs[x][l[x]]);
        ++l[x];
        return true;
    }
    else return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        hs[a[i]].pb(i);
    }

    k = -1;
    while (1) {
        int x = 1;
        while (k+x >= 0) {
            if (Check(k+x)) break;
            x-=3;
        }
        if (k+x < 0) break;
        else k+=x;
    }

    if (ans.size() != n) printf("Impossible");
    else {
        printf("Possible\n");
        forit(it, vector<int>, ans) printf("%d ", *it);
    }

    return 0;
}