#include<cstring>

#include<cstdio>

#include<vector>

#include<set>

#include<map>

#include<algorithm>

#include<string>

#include<cstdlib>

using namespace std;
long long n, m, k, modulo = 1000000009;


void mul(long long (&a)[2][2], long long (&b)[2][2], long long (&c)[2][2])
{
    long long d[2][2];
    memset(d, 0, sizeof(d));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                d[i][j] = (d[i][j] + a[i][k] * b[k][j] % modulo) % modulo;
    memcpy(c, d, sizeof(c));
}
long long calc(int len)
{
    long long G[2][2], result[2][2];
    G[0][0] = 2;
    G[0][1] = 2 * k;
    G[1][0] = 0;
    G[1][1] = 1;
    result[0][0] = 1;
    result[0][1] = 0;
    result[1][0] = 0;
    result[1][1] = 1;
    while(len)
    {
        if(len % 2 == 1) mul(result, G, result);
        len >>= 1;
        mul(G, G, G);
    }
    return (result[0][1]) % modulo;
}
int main()

{
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if(m <= n - n / k)
    {
        printf("%I64d\n", m);
    }else
    {
        printf("%I64d\n", (calc(m - (n - n / k)) + (m - k * (m - (n - n / k)) % modulo + modulo) % modulo) % modulo);
    }

    fclose(stdin);

    return 0;

}