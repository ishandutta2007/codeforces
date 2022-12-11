#include <bits/stdc++.h>
using namespace std;

int buf[40004];
constexpr int *presum = &buf[1];

void proc()
{
        int a, b, q;
        scanf("%d%d%d",&a,&b,&q);
        for (int i = 0; i < a * b; i++)
        {
                presum[i] = presum[i - 1];
                if ((i % a) % b != (i % b) % a) presum[i]++;
        }

        while (q--)
        {
                long long l, r;
                scanf("%lld%lld", &l, &r);
                printf("%lld ",
                        presum[a * b - 1] - presum[l % (a * b) - 1] +
                        presum[r % (a * b)] +
                        presum[a * b - 1] * (r / (a * b) - l / (a * b) - 1)
                );
        }

        printf("\n");
}

int main()
{
        int T;
        scanf("%d",&T);
        while (T--) proc();
}