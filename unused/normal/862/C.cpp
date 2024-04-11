#include <bits/stdc++.h>
using namespace std;

void printans(const vector<int> &vt)
{
    printf("YES\n");
    for (int t : vt) printf("%d ", t);
    printf("\n");
    exit(0);
}

bool used[1000005];

int main()
{
    int n, x;
    scanf("%d%d",&n,&x);

    if (x == 0)
    {
        if (n == 1) printans({0});
        if (n == 2)
        {
            printf("NO\n");
            return 0;
        }
        vector<int> ans;

        for (int i = 100001; n > 6; i += 2)
        {
            ans.push_back(i);
            ans.push_back(524287 - i);
            ans.push_back(i + 1);
            ans.push_back(524287 - i - 1);
            n -= 4;
        }

        vector<int> ans2;

        if (n == 3) ans2 = {1, 2, 3};
        if (n == 4) ans2 = {1, 2, 4, 7};
        if (n == 5) ans2 = {1, 2, 4, 8, 15};
        if (n == 6) ans2 = {1, 2, 4, 8, 16, 31};

        for (int t : ans2) ans.push_back(t);

        printans(ans);
    }

    if (n == 1)
    {
        printans({x});
    }
    if (n == 2)
    {
        if (x == 0)
        {
            printf("NO\n");
            return 0;
        }
        printans({x, 0});
    }

    vector<int> ans;

    for (int i = 100001; ans.size() + 4 < n; i += 2)
    {
        ans.push_back(i);
        ans.push_back(524287 - i);
        ans.push_back(i + 1);
        ans.push_back(524287 - i - 1);
    }

    if (ans.size() + 1 == n)
    {
        ans.push_back(x);
    }
    else if (ans.size() + 2 == n)
    {
        ans.push_back(x ^ 524288);
        ans.push_back(524288);
    }
    else if (ans.size() + 3 == n)
    {
        ans.push_back(x ^ 524288);
        ans.push_back(x ^ 524288 ^ 262144);
        ans.push_back(x ^ 262144);
    }
    else if (ans.size() + 4 == n)
    {
        ans.push_back(x);
        ans.push_back(524288);
        ans.push_back(262144);
        ans.push_back(524288 ^ 262144);
    }

    printans(ans);
}