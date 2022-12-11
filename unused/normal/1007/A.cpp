#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a, a + n);
    multiset<int> st(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto itr = st.upper_bound(a[i]);
        if (itr != st.end())
        {
            ++ans;
            st.erase(itr);
        }
    }

    printf("%d\n", ans);
}