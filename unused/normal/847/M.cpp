#include <bits/stdc++.h>
using namespace std;

int z[105];

int main()
{
    set<int> st;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&z[i]);
    st.insert(z[1]-z[0]);
    for (int i = 2; i < n; i++)
    {
        if (st.insert(z[i]-z[i-1]).second)
        {
            printf("%d\n", z[n-1]);
            return 0;
        }
    }
    printf("%d\n",z[n-1]*2-z[n-2]);
}