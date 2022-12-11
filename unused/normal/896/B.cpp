#include <bits/stdc++.h>
using namespace std;

vector<int> L, R;

int main()
{
    int n, m, c; scanf("%d%d%d",&n,&m,&c);
    
    while (L.size() + R.size() < n)
    {
        int x; scanf("%d",&x);
        if (x <= c / 2)
        {
            auto itr = upper_bound(L.begin(), L.end(), x);
            if (itr == L.end())
            {
                L.push_back(x);
                itr = prev(L.end());
            }
            else *itr = x;
            printf("%d\n", (int)(itr - L.begin() + 1));
        }
        else
        {
            x = -x;
            auto itr = upper_bound(R.begin(), R.end(), x);
            if (itr == R.end())
            {
                R.push_back(x);
                itr = prev(R.end());
            }
            else *itr = x;
            printf("%d\n", n - (int)(itr - R.begin()));
        }
        fflush(stdout);
    }
}