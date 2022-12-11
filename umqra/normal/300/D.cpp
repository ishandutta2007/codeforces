#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
const int mod = 7340033;
const int K = 14;
const int pow2 = (1 << K);
const int MAXK = 1001;
const int mainRoot = 1226;//12625;//2001861;//772;
const int H = 30;

int rev[pow2];
bool cool[mod];
int root[pow2];
int dp[H + 1][pow2];
int tmp[pow2], arr[pow2];

int add(int a, int b)
{
    a += b;
    if (a < 0)
        return a + mod;
    if (a < mod)
        return a;
    return a - mod;
}

int mult(int a, int b)
{
    ll c = (ll)a * b;
    return c % mod;
}

int myPow(int a, int k)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return mult(a, myPow(a, k - 1));
    else
    {
        int t = myPow(a, k / 2);
        return mult(t, t);
    }
}

int getDeep(int n)
{
    int h = 0;
    while (n > 1)
    {
        if (!(n & 1))
            break;
        h++;
        n /= 2;
    }
    return h;
}

int getAns(int h, int k)
{
    return dp[h][k];
}

void precalc()
{
    rev[0] = 0;
    int higher = -1;
    for (int i = 1; i < pow2; i++)
    {
        if ((i & (i - 1)) == 0)
            higher++;
        rev[i] = rev[i ^ (1 << higher)];
        rev[i] |= (1 << (K - higher - 1));
    }
    root[0] = 1;
    for (int i = 1; i < pow2; i++)
        root[i] = mult(root[i - 1], mainRoot);
}

void fft(int *source)
{
    for (int i = 0; i < pow2; i++)
        tmp[rev[i]] = source[i];

    for (int len = 1; len < pow2; len *= 2)
    {
        for (int pos = 0; pos < pow2; pos += 2 * len)
        {
            int idRoot = 0;
            int step = pow2 / (2 * len);
            for (int i = 0; i < len; i++)
            {
                int val = mult(root[idRoot], tmp[pos + i + len]);
                source[pos + i] = add(tmp[pos + i], val);
                source[pos + i + len] = add(tmp[pos + i], -val);
                idRoot += step;
            }
        }
/*      puts("Sorce:");
        for (int i = 0; i < 8; i++)
            printf("(root = %d, val = %d) ", root[i], source[i]);
*/      copy(source, source + pow2, tmp);
    }
}

void calcSquare(int *source, int *dest)
{
    copy(source, source + pow2, arr);
    fft(arr);
    for (int i = 0; i < pow2; i++)
        arr[i] = mult(arr[i], arr[i]);
    
    fft(arr);
    reverse(arr + 1, arr + pow2);
    for (int i = 0; i < pow2; i++)
        arr[i] = mult(arr[i], myPow(pow2, mod - 2));
    copy(arr, arr + pow2, dest);
}

void changePolynom(int *source)
{
    for (int i = pow2 - 1; i > 0; i--)
        source[i] = source[i - 1];
    source[0] = 1;
    for (int i = MAXK + 1; i < pow2; i++)
        source[i] = 0;
}

void calcAns()
{
    dp[0][0] = 1;
    for (int i = 0; i < H; i++)
    {
        calcSquare(dp[i], dp[i + 1]);
//      printf("dp[i] ^ 2:\n");
//      for (int s = 0; s < 8; s++)
//          printf("%d ", dp[i + 1][s]);
//      puts("");
        calcSquare(dp[i + 1], dp[i + 1]);
        changePolynom(dp[i + 1]);
    }
/*  for (int i = 0; i <= H; i++)
    {
        printf("depp = %d\n", i);
        for (int s = 0; s < 8; s++)
            printf("%d ", dp[i][s]);
        puts("");
    }*/
}

void findRoot()
{
    for (int i = 0; i < mod; i++)
    {
        cool[i] = (myPow(i, pow2) == 1 ? 1 : 0);
    }
    for (int i = 2; i < mod; i++)
    {
        int x = i;
        bool ok = true;
        for (int s = 0; s < pow2; s++)
        {
            if (!cool[x] || (s != 0 && x == i))
            {
                ok = false;
                break;
            }
            x = mult(x, i);
        }
        if (x != i)
            ok = false;
        if (ok)
        {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
//  findRoot();
//  return 0;
    precalc();
    calcAns();
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int n, k;
        scanf("%d%d", &n, &k);

        int h = getDeep(n);
        printf("%d\n", getAns(h, k));
    }

    return 0;
}