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
#define maxN 5000001
#define mod 1000000009

int fd[maxN];
ll f[maxN], ff[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int lim = trunc(sqrt(maxN));
    fd[1] = 1;
    fto(i, 2, lim)
        if (fd[i] == 0)
        {
            fd[i] = 1;
            int j = i*i;
            while (j <= maxN) {
                fd[j] = i;
                j+=i;
            }
        }
    fto(i, lim+1, maxN) if (fd[i] == 0) fd[i] = 1;

    //fto(i, 1, 10) printf("%d ", fd[i]);

    f[1] = (ll)0;
    fto(i, 2, maxN) {
        if (fd[i] == 1) f[i] = 1;
        else f[i] = f[fd[i]]+f[i/fd[i]];
    }
    //fto(i, 1, 10) printf("%d ", f[i]);

    ff[1] = (ll)0;
    fto(i, 2, maxN) ff[i] = ff[i-1]+f[i];

    int nTest;
    scanf("%d", &nTest);
    while (nTest--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%I64d\n", ff[a]-ff[b]);
    }

    return 0;
}