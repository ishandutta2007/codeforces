#include <bits/stdc++.h>
using namespace std;

char str[444444];
int cnt[256];
int n;
char yes[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static_assert(sizeof(yes) == 10 + 26 + 26 + 1, "");
vector<int> odd;

void check(int t)
{
    int cnt = n / t;

    if (t & 1)
    {
        if (odd.size() > cnt) return;

        for (int j = 0; odd.size() < cnt; j++)
        {
            if (::cnt[j] == 0) continue;
            ::cnt[j] -= 2;
            odd.push_back(j);
            odd.push_back(j);
            --j;
        }

        printf("%d\n", cnt);
        int j = 0;
        for (int i = 0; i < cnt; i++)
        {
            string res;
            while (res.size() < t / 2)
            {
                while (::cnt[yes[j]] == 0) ++j;
                ::cnt[yes[j]] -= 2;
                res.push_back(yes[j]);
            }

            printf("%s%c", res.c_str(), odd.back());
            odd.pop_back();
            reverse(res.begin(), res.end());
            printf("%s ", res.c_str());
        }

        printf("\n");
        exit(0);
    }
    else
    {
        if (odd.empty() == false) return;

        printf("%d\n", cnt);
        int j = 0;
        for (int i = 0; i < cnt; i++)
        {
            string res;
            while (res.size() < t / 2)
            {
                while (::cnt[yes[j]] == 0) ++j;
                ::cnt[yes[j]] -= 2;
                res.push_back(yes[j]);
            }

            printf("%s", res.c_str());
            reverse(res.begin(), res.end());
            printf("%s ", res.c_str());
        }

        printf("\n");
        exit(0);
    }
}

int main()
{
    scanf("%d%s",&n,str);

    for (int i = 0; i < n; i++)
    {
        cnt[str[i]]++;
    }

    for (int j : yes)
    {
        if (cnt[j] & 1)
        {
            odd.push_back(j);
            cnt[j]--;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (n % i == 0) check(i);
    }
}