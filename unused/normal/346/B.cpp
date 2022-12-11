#include <bits/stdc++.h>
using namespace std;

typedef string seq_t;
void calculate_pi(vector<int>& pi, const seq_t& str) {
    pi.resize(str.size());
    pi[0] = -1;
    for (int i = 1, j = -1; i < str.size(); i++) {
        while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
        if (str[i] == str[j + 1])
            pi[i] = ++j;
        else
            pi[i] = -1;
    }
}

string s1, s2, virus;
vector<int> pi;

int dp[101][101][101];
bool v[101][101][101];

int D(int a, int b, int j)
{
    if (a == s1.size() || b == s2.size()) return 0;

    if (v[a][b][j + 1] == false)
    {
        v[a][b][j + 1] = true;
        dp[a][b][j + 1] = max(D(a + 1, b, j), D(a, b + 1, j));

        int oldj = j;

        if (s1[a] == s2[b])
        {
            while (j >= 0 && s1[a] != virus[j + 1]) j = pi[j];
            if (s1[a] == virus[j + 1]) ++j;

            if (j + 1 < virus.size())
            {
                dp[a][b][oldj + 1] = max(dp[a][b][oldj + 1], D(a + 1, b + 1, j) + 1);
            }
        }

        return dp[a][b][oldj + 1];
    }

    return dp[a][b][j + 1];
}

void recur(int a, int b, int j)
{
    if (D(a, b, j) == 0) return;
    if (D(a, b, j) == D(a + 1, b, j)) recur(a + 1, b, j);
    else if (D(a, b, j) == D(a, b + 1, j)) recur(a, b + 1, j);
    else
    {
        printf("%c", s1[a]);
        while (j >= 0 && s1[a] != virus[j + 1]) j = pi[j];
        if (s1[a] == virus[j + 1]) ++j;
        recur(a + 1, b + 1, j);
    }
}

int main()
{
    cin >> s1 >> s2 >> virus;
    calculate_pi(pi, virus);

    recur(0, 0, -1);
    if (D(0, 0, -1) == 0) printf("0\n");
    else printf("\n");
}