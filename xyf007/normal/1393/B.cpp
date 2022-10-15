#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int n, q;
map<int, int> cnt;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0; // cnt0 : >= 8; cnt1 : >= 6; cnt2 : >= 4; cnt3 : >=0
    for (auto &&i : cnt)
    {
        if (i.second >= 8)
        {
            cnt0++;
        }
        else
        {
            if (i.second >= 6)
            {
                cnt1++;
            }
            else
            {
                if (i.second >= 4)
                {
                    cnt2++;
                }
                else
                {
                    if (i.second >= 2)
                    {
                        cnt3++;
                    }
                }
            }
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        char op[5];
        int x;
        scanf("%s%d", op, &x);
        if (op[0] == '+')
        {
            cnt[x]++;
            if (cnt[x] == 2)
            {
                cnt3++;
            }
            else
            {
                if (cnt[x] == 4)
                {
                    cnt3--;
                    cnt2++;
                }
                else
                {
                    if (cnt[x] == 6)
                    {
                        cnt2--;
                        cnt1++;
                    }
                    else
                    {
                        if (cnt[x] == 8)
                        {
                            cnt1--;
                            cnt0++;
                        }
                    }
                }
            }
        }
        else
        {
            cnt[x]--;
            if (cnt[x] == 7)
            {
                cnt0--;
                cnt1++;
            }
            else
            {
                if (cnt[x] == 5)
                {
                    cnt1--;
                    cnt2++;
                }
                else
                {
                    if (cnt[x] == 3)
                    {
                        cnt2--;
                        cnt3++;
                    }
                    else
                    {
                        if (cnt[x] == 1)
                        {
                            cnt3--;
                        }
                    }
                }
            }
        }
        if (cnt0 || (cnt1 && ((cnt1 - 1) || cnt2 || cnt3)))
        {
            printf("YES\n");
        }
        else
        {
            if (cnt2 >= 2 || (cnt2 == 1 && cnt3 >= 2))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}