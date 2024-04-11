#include <bits/stdc++.h>
using namespace std;

char a[1000005], b[1000005];
int num[26], num2[26];

int main()
{
    scanf("%s%s", a, b);

    int fre = 0;

    for (int i = 0; a[i]; i++) if (a[i] == '?') ++fre; else num[a[i] - 'a']++;
    for (int i = 0; b[i]; i++) num2[b[i] - 'a']++;

    int lo = 1, hi = 1000000, ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        long long need = 0;

        for (int j = 0; j < 26; j++)
        {
            need += max(0LL, mid * 1ll * num2[j] - num[j]);
        }

        if (need <= fre)
        {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    vector<char> vt;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < ans * 1ll * num2[i] - num[i]; j++) vt.push_back(i + 'a');
    }

    for (int i = 0; a[i]; i++)
    {
        if (a[i] == '?')
        {
            if (vt.empty()) vt.push_back('a');
            printf("%c", vt.back());
            vt.pop_back();
        }
        else printf("%c", a[i]);
    }
    printf("\n");
}