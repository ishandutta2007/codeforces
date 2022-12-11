#include <bits/stdc++.h>
using namespace std;

namespace conv
{

    typedef long long T;
    int n, invn;
    T mod;

    //wewnetrzne funkcje
    T power(T a, T b)
    {
        if(b == 0) return 1;
        if(b & 1) return power(a, b - 1) * a % mod;
        return power(a * a % mod, b / 2);
    }

    T inv(T x)
    {
        return power(x, mod - 2);
    }

    void convolve(T *tab, vector<vector<int>> M)
    {
        for(int i = 1; i < n; i *= 2)
            for(int j = 0; j < n; j += 2 * i)
                for(int k = 0; k < i; k++)
                {
                    T &a = tab[j + k], &b = tab[j + i + k];
                    T na = (M[0][0] * a + M[0][1] * b) % mod, nb = (M[1][0] * a + M[1][1] * b) % mod;
                    a = na; b = nb;
                }
    }

    void mult(T *a, T *b, T *c)
    {
        for(int i = 0; i < n; i++)
            c[i] = a[i] * b[i] % mod;
    }

    //tych funkcji uzywac
    //N MUSI byc potega dwojki
    void init(int N, T Mod)
    {
        mod = Mod;
        n = N;
        invn = inv(n);
    }

    //UWAGA modyfikuje tablice a i b, robic kopie jesli potrzebne pozniej
    void xor_conv(T *a, T *b, T *res)
    {
        convolve(a, { { 1, 1 }, { 1, -1 } });
        if(a != b) convolve(b, { { 1, 1 }, { 1, -1 } });
        mult(a, b, res);
        convolve(res, { { 1, 1 }, { 1, -1 } });
        for(int i = 0; i < n; i++)
            res[i] = res[i] * invn % mod;
    }

    void and_conv(T *a, T *b, T *res)
    {
        convolve(a, { { 0, 1 }, { 1, 1 } });
        if(a != b) convolve(b, { { 0, 1 }, { 1, 1 } });
        mult(a, b, res);
        convolve(res, { { -1, 1 }, { 1, 0 } });
    }

}

namespace subset_conv
{
    typedef long long T;
    const int B = 17, N = 1 << B;
    const T mod = 1000000007;
    
    T tA[B+1][N];
    T tB[B+1][N];
    T conv[B+1][N];
    int cnt[N];

    void sum_over_subset(T *a, T *b, int k = -1)
    {
        for(int i = 0; i < N; i++)
            b[i] = (k == -1 || k == cnt[i]) * a[i];
        for(int i = 0; i < B; i++)
            for(int j = 0; j < N; j++)
                if(j & (1 << i))
                    b[j] += b[j ^ (1 << i)];
        for(int i = 0; i < N; i++)
            b[i] %= mod;
    }
    
    void mobius_transform(T *a, T b[B+1][N])
    {
        for(int i = 0; i <= B; i++)
            sum_over_subset(a, b[i], i);
    }
    
    void subset_conv(T *a, T *b, T *res)
    {
        for(int i = 0; i < N; i++)
            cnt[i] = __builtin_popcount(i);
        mobius_transform(a, tA);
        if(a != b)
            mobius_transform(b, tB);
        else copy(tA[0], tA[0] + (B+1)*N, tB[0]);
        for(int i = 0; i <= B; i++)
            for(int j = 0; j < N; j++)
                conv[i][j] = 0;
        for(int i = 0; i <= B; i++)
            for(int j = 0; i + j <= B; j++)
                for(int k = 0; k < N; k++)
                {
                    conv[i+j][k] += tA[i][k] * tB[j][k];
                    if(conv[i+j][k] >= (1LL << 62))
                        conv[i+j][k] %= mod;
                }
        for(int i = 0; i <= B; i++)
            for(int j = 0; j < N; j++)
            {
                conv[i][j] %= mod;
                if(cnt[j] & 1)
                    conv[i][j] *= -1;
            }
        for(int i = 0; i <= B; i++)
            sum_over_subset(conv[i], conv[i]);
        for(int i = 0; i < N; i++)
        {
            res[i] = conv[cnt[i]][i];
            if(cnt[i] & 1)
                res[i] *= -1;
        }
    }

}

typedef long long ll;
const int mod = 1000000007;
const int B = 17, N = 1 << B;

const int K = 5;
ll fib[N];
ll tab[K][N];

int main()
{
    conv::init(N, mod);
    
    fib[1] = 1;
    for(int i = 2; i < N; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        tab[0][s]++; tab[1][s]++; tab[2][s]++;
    }
    
    conv::mult(fib, tab[0], tab[0]);
    
    conv::xor_conv(tab[1], tab[1], tab[3]);
    conv::mult(fib, tab[3], tab[1]);
    
    subset_conv::subset_conv(tab[2], tab[2], tab[4]);
    conv::mult(fib, tab[4], tab[2]);
    
    conv::and_conv(tab[0], tab[1], tab[3]);
    conv::and_conv(tab[2], tab[3], tab[4]);
    
    ll ans = 0;
    for(int i = 0; i < 17; i++)
        ans += tab[4][1 << i];
    
    ans %= mod;
    if(ans < 0) ans += mod;
    
    printf("%lld\n", ans);
}