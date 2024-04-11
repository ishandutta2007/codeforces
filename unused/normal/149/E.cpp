#include <bits/stdc++.h>
using namespace std;

typedef string seq_t;

string str, rstr;

void calculate_pi(vector<int>& p, const seq_t& s) {
    p[0] = -1;
    for (int i = 1, j = -1; i < s.size(); i++) {
        while (j >= 0 && s[i] != s[j + 1]) j = p[j];
        if (s[i] == s[j + 1])
            p[i] = ++j;
        else
            p[i] = -1;
    }
}

// returns all positions matched
// O(|text|+|pattern|)
vector<int> kmp(const seq_t& text, const seq_t& pattern) {
    vector<int> p(pattern.size());
    calculate_pi(p, pattern);
    vector<int> ret;
    for (int i = 0, j = -1; i < text.size(); i++) {
        while (j >= 0 && text[i] != pattern[j + 1]) j = p[j];
        if (text[i] == pattern[j + 1]) {
            j++;
            ret.push_back(j + 1);
            if (j + 1 == pattern.size()) {
                j = p[j];
            }
        }
        else
        {
            ret.push_back(j + 1);
        }
    }
    return ret;
}

int main()
{
    cin.sync_with_stdio(false);

    cin >> str;
    rstr = { str.rbegin(), str.rend() };

    int n;
    cin >> n;
    int ans = 0, ans2 = 0;
    while (n--)
    {
        string test;
        cin >> test;
        if (test.size() == 1)
        {
            continue;
        }

        string rtest(test.rbegin(), test.rend());
        auto r1 = kmp(str, test);
        auto r2 = kmp(rstr, rtest);
        reverse(r2.begin(), r2.end());

        for (int i = 1; i < r1.size(); i++) r1[i] = max(r1[i], r1[i - 1]);
        for (int i = (int)r2.size() - 2; i >= 0; i--) r2[i] = max(r2[i], r2[i + 1]);

        for (int i = 0; i < r1.size() - 1; i++)
        {
            if (r1[i] + r2[i + 1] >= test.size())
            {
                ++ans;
                break;
            }
        }
    }

    printf("%d\n", ans);
}