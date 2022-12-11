#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100001, inf = 1e9;
int a[N];
int d[N];
int lt[N];
int rt[N];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i < n; i++)
        d[i] = abs(a[i] - a[i+1]);
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        vector<pair<int, int>> st = { { inf, l - 1 } };
        for(int i = l; i < r; i++)
        {
            while(d[i] >= st.back().first)
                st.pop_back();
            lt[i] = st.back().second;
            st.push_back({ d[i], i });
        }
        st = { { inf, r } };
        for(int i = r - 1; i >= l; i--)
        {
            while(d[i] > st.back().first)
                st.pop_back();
            rt[i] = st.back().second;
            st.push_back({ d[i], i });
        }
        ll ans = 0;
        for(int i = l; i < r; i++)
            ans += 1LL * d[i] * (i - lt[i]) * (rt[i] - i);
        printf("%lld\n", ans);
    }
}