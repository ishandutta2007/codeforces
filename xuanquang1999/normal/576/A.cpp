using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
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

int n, maxcnt[maxN], sum;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);

    fto(i, 1, n) {
        int k = i;
        fto(j, 2, n) {
            int cnt = 0;
            while (k%j == 0) {
                ++cnt;
                k/=j;
            }
            maxcnt[j] = max(maxcnt[j], cnt);
        }
    }

    fto(i, 1, n) sum+=maxcnt[i];
    printf("%d\n", sum);
    fto(i, 1, n) {
        int k = 1;
        fto(j, 1, maxcnt[i]) {
            k *= i;
            printf("%d ", k);
        }
    }

    return 0;
}