#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    long long total = accumulate(a+1, a+1+n, 0LL);
    if (total & 1)
    {
        printf("NO\n");
        return 0;
    }
    total /= 2;
    long long now = 0;
    multiset<long long> st;
    st.insert(0);
    for (int i = 1; i <= n + 1; i++)
    {
        if (st.find(now - total) != st.end())
        {
            printf("YES\n");
            return 0;
        }

        st.insert(a[i]);
        now += a[i];
    }

    st.clear();
    st.insert(0);
    now = 0;
    for (int i = n; i >= 0; i--)
    {
        if (st.find(now - total) != st.end())
        {
            printf("YES\n");
            return 0;
        }

        st.insert(a[i]);
        now += a[i];
    }

    printf("NO\n");
}