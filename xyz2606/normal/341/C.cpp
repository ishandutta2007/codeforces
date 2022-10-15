#include<cstring>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<cmath>

#include<cstdlib>

#include<ctime>

#include<queue>

using namespace std;

int Q, n, m, k, a[111111];

long long x, y, z, ans, C, modulo = 1000000007, coe1, coe2;

void exgcd(const long long & a, const long long & b)

{

    if(b == 0)

    {

        coe1 = 1; coe2 = 0;

    }else

    {

        exgcd(b, a % b);

        coe1 -= a / b * coe2;

        swap(coe1, coe2);

    }

}

long long rev(const long long a)

{

    exgcd(a, modulo);

    return (coe1 % modulo + modulo) % modulo;

}

int main()

{


    scanf("%d", &n);

    k = 0;

    for(int i = 1; i <= n; i++)

    {

        scanf("%d", &a[i]);

        if(a[i] == -1) k++;

    }

    m = 0;

    for(int i = 1; i <= n; i++)

        if(a[i] != -1 and a[a[i]] == -1) m++;

    x = -1; y = 1;

    for(int i = 1; i <= k - m; i++)

    {

        z = (i - 1) * ((x + y) % modulo) % modulo;

        x = y; y = z;

    }

    ans = y;

    C = 1;

    for(int i = 1; i <= m; i++)

    {

        C = C * (m - i + 1) % modulo;

        C = C * rev(i) % modulo;

        z = (k - m + i - 1) * ((x + y) % modulo) % modulo;

        x = y; y = z;

        ans = (ans + (z * C) % modulo) % modulo;        

    }

    printf("%I64d\n", ans);

    fclose(stdin);

    return 0;

}