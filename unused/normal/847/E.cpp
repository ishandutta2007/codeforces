#include <bits/stdc++.h>
using namespace std;

char dat[100005];

vector<int> pac;
vector<int> foo;

int getcost(int L, int M, int R)
{
    if (R <= M) return M - L;
    if (L >= M) return R - M;

    return min(M - L, R - M) * 2 + max(M - L, R - M);
}

bool check(int t)
{
    int L = 0, R = 0;
    while (L < pac.size() && R < foo.size())
    {
        int nxt = (L == pac.size() - 1) ? INT_MAX : pac[L + 1];
        if (nxt < foo[R])
        {
            ++L;
            continue;
        }

        int RR = R;
        while (RR < foo.size() && foo[RR] < nxt && getcost(foo[R], pac[L], foo[RR]) <= t) ++RR;
        R = RR;
        ++L;
    }

    return R == foo.size();
}

int main()
{
    int n;
    scanf("%d%s", &n, dat);
    for (int i = 0; i < n; i++) if (dat[i] == 'P') pac.push_back(i); else if (dat[i] == '*') foo.push_back(i);

    int lo = 1, hi = 2 * n - 1, ans = 2 * n;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    printf("%d\n", ans);
}