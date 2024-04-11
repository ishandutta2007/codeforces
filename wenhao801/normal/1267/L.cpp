#include <cstdio>

typedef long long ll;
ll read()
{
    ll ret = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret;
}

int N, L, K, a[27], al, l;
char nex()
{
    while (!a[al]) ++al; --a[al];
    return al + 'a';
}

char ANS[1005][1005], S[1000005];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d%d%s", &N, &L, &K, S + 1); int i, j;
    for (i = 1; i <= N * L; ++i) ++a[S[i] - 'a'];
    l = 1;
    for (i = 1; i <= L; ++i)
    {
        for (j = l; j <= K; ++j) ANS[j][i] = nex();
        for (j = K; j >= 1 && ANS[j][i] == ANS[K][i]; --j); ++j;
        l = j;
    }
    for (i = 1; i <= L; ++i) for (j = 1; j <= N; ++j) if (!ANS[j][i]) ANS[j][i] = nex();
    for (i = 1; i <= N; ++i) puts(ANS[i] + 1);
    return 0;
}