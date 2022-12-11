#include <bits/stdc++.h>
using namespace std;

char str[100005];
int len;
int cnt[3];

string ans;

void updatehubo(const string &str)
{
    if (ans.size() < str.size()) ans = str;
}

void delone(int rem)
{
    if (cnt[rem] < 1) return;

    string z;
    int t = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if ((str[i] - '0') % 3 != rem) z.push_back(str[i]);
        else
        {
            if (t == 0) z.push_back(str[i]);
            else --t;
        }
    }

    while (z.size() > 1 && z.back() == '0') z.pop_back();
    reverse(z.begin(), z.end());
    updatehubo(z);
}

void deltwo(int rem)
{
    if (cnt[rem] < 2) return;

    string z;
    int t = 2;
    for (int i = len - 1; i >= 0; i--)
    {
        if ((str[i] - '0') % 3 != rem) z.push_back(str[i]);
        else
        {
            if (t == 0) z.push_back(str[i]);
            else --t;
        }
    }

    while (z.size() > 1 && z.back() == '0') z.pop_back();
    reverse(z.begin(), z.end());
    updatehubo(z);
}

int main()
{
    scanf("%s",str);
    int sum = 0;
    for (len = 0; str[len]; len++)
    {
        sum = (sum + str[len] - '0') % 3;
        cnt[(str[len] - '0') % 3]++;
    }

    if (sum == 0)
    {
        printf("%s\n", str);
        return 0;
    }

    if (sum == 1)
    {
        delone(1);
        deltwo(2);
    }

    if (sum == 2)
    {
        delone(2);
        deltwo(1);
    }

    if (ans.empty()) printf("-1\n");
    else printf("%s\n", ans.c_str());
}