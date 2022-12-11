#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> nxt[100005];
int n;
int dat[100005];
constexpr int B = 400;

void build(int L, int R)
{
        for (int i = R; i >= L; i--)
        {
                if (dat[i] + i > R)
                {
                        nxt[i] = {dat[i] + i, i, 1};
                }
                else
                {
                        nxt[i] = nxt[dat[i] + i];
                        get<2>(nxt[i])++;
                }
        }
}

int main()
{
        int m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
        {
                scanf("%d",&dat[i]);
        }

        for (int i = 0; i < n; i += B)
        {
                build(i, min(n - 1, i + B - 1));
        }

        for (int i = 0; i < m; i++)
        {
                int x;
                scanf("%d",&x);
                if (x == 0)
                {
                        int a, b;
                        scanf("%d%d",&a,&b);
                        --a;
                        dat[a] = b;
                        build(a / B * B, min(n - 1, a / B * B + B - 1));
                }
                else
                {
                        int ans2 = 0;
                        int y, y2;
                        scanf("%d",&y);
                        --y;
                        while (y < n)
                        {
                                ans2 += get<2>(nxt[y]);
                                tie(y, y2, ignore) = nxt[y];
                        }

                        printf("%d %d\n", y2 + 1, ans2);
                }
        }
}