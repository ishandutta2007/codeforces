#include <bits/stdc++.h>
using namespace std;

string dat, text;
vector<int> pi;

pair<int, int> nxt[50005][26];
vector<int> dp1, dp2;

void calculate_pi() {
    pi.resize(text.size());
    pi[0] = -1;
    for (int i = 1, j = -1; i < text.size(); i++) {
        while (j >= 0 && text[i] != text[j + 1]) j = pi[j];
        if (text[i] == text[j + 1])
            pi[i] = ++j;
        else
            pi[i] = -1;
    }

    for (int i = 0; i < 26; i++) nxt[0][i] = {0, (text[0] == i + 'a') ? 0 : -1};

    for (int j = 0; j + 1 < text.size(); j++)
    {
        for (int ch = 'a'; ch <= 'z'; ch++)
        {
            int a = 0;
            int k = j;

            if (ch == text[k + 1])
            {
                ++k;
                if (k + 1 == text.size()) nxt[j + 1][ch - 'a'] = {1, pi[k]};
                else nxt[j + 1][ch - 'a'] = {0, k};
            }
            else
            {
                nxt[j + 1][ch - 'a'] = nxt[k == -1 ? 0 : pi[k] + 1][ch - 'a'];
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> dat >> text;

    if (text.size() == 1)
    {
        printf("%d\n", (int)(count(dat.begin(), dat.end(), text[0]) + count(dat.begin(), dat.end(), '?')));
        return 0;
    }

    if (dat.size() < text.size())
    {
        printf("0\n");
        return 0;
    }

    calculate_pi();

    dp1.resize(text.size(), -2e9);
    dp2.resize(text.size());
    dp1[0] = dp2[0] = 0;

    for (int i = 0; i < dat.size(); i++, swap(dp1, dp2))
    {
        for (int j = 0; j < text.size(); j++) dp2[j] = -2e9;
        int lo, hi;
        if (dat[i] == '?') lo = 0, hi = 25;
        else lo = hi = dat[i] - 'a';

        for (int i = 0; i < text.size(); i++)
        {
            for (int j = lo; j <= hi; j++)
            {
                int a, b;
                tie(a, b) = nxt[i][j];
                dp2[b + 1] = max(dp2[b + 1], a + dp1[i]);
            }
        }
    }

    printf("%d\n", *max_element(dp1.begin(), dp1.end()));
}