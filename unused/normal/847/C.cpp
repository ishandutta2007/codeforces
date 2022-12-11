#include <bits/stdc++.h>
using namespace std;

string L, R;

int main()
{
    int n; long long k;
    scanf("%d%lld",&n,&k);

    if (n * 1ll * (n - 1) / 2 < k)
    {
        printf("Impossible\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (n - i - 1 <= k)
        {
            k -= n - i - 1;
            L.push_back('(');
            R.push_back(')');
        }
        else
        {
            L.push_back('(');
            L.push_back(')');
        }
    }

    reverse(R.begin(), R.end());
    printf("%s%s\n", L.c_str(), R.c_str());
}