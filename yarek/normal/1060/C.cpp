#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &tab)
{
    int n = tab.size();
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 0; j < i; j++)
            sum += tab[j];
        ans[i] = sum;
        for(int j = i; j < n; j++)
        {
            sum += tab[j] - tab[j-i];
            ans[i] = min(ans[i], sum);
        }
//         printf("%d ", ans[i]);
    }
//     puts("");
    return ans;
}

int main()
{
    int n, m, x;
    scanf("%d %d", &n, &m);
    vector<int> a(n), b(m);
    for(auto &y: a)
        scanf("%d", &y);
    for(auto &y: b)
        scanf("%d", &y);
    scanf("%d", &x);
    int ans = 0;
    auto ta = f(a), tb = f(b);
    for(int i = 1; i < ta.size(); i++)
        for(int j = 1; j < tb.size(); j++)
            if(1LL * ta[i] * tb[j] <= x)
                ans = max(ans, i * j);
    printf("%d\n", ans);
}