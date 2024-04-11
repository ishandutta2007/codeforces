#include <bits/stdc++.h>
using namespace std;

string str;

bool X[27][27];

int dp[100005][27];
bool v[100005][27];

int D(int idx, int last)
{
    if (idx == str.size()) return 0;

    if (v[idx][last] == false)
    {
        v[idx][last] = true;

        dp[idx][last] = D(idx + 1, last) + 1;
        if (X[last][str[idx] - 'a'] == false)
        {
            dp[idx][last] = min(dp[idx][last], D(idx + 1, str[idx] - 'a'));
        }
    }
    return dp[idx][last];
}

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> str >> n;
    for (int i = 0; i < n; i++)
    {
        string z;
        cin >> z;
        X[z[0]-'a'][z[1]-'a'] = X[z[1]-'a'][z[0]-'a'] = true;
    }

    printf("%d\n", D(0, 26));
}