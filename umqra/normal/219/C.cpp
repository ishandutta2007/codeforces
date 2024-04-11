#include <iostream>
#include <string>
using namespace std;
const int N = (int)5e5 + 5;
int dp[N][30];
string str;

int make_ans(int pos, int m, char s)
{
    if (pos < 0)
        return 0;
    int r = N * 100;    
    char c;
    for (char i = 'A'; i < 'A' + m; i++)
    {
        if (r > dp[pos][i - 'A'] && i != s)
        {
            r = dp[pos][i - 'A'];
            c = i;
        }
    }
                       
    str[pos] = c;

    make_ans(pos - 1, m, c);

    return r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < (int)str.length(); i++)
    {
        int r = N;
        for (char a = 'A'; a < 'A' + m; a++)
        {
            dp[i][a - 'A'] = N * 100;
            if (!i)
                dp[i][a - 'A'] = (str[i] == a) ? 0 : 1;
            else 
            {
                for (char q = 'A'; q < 'A' + m; q++)
                {
                    if (dp[i - 1][q - 'A'] != -1 && q != a)
                        dp[i][a - 'A'] = min(dp[i][a - 'A'], dp[i - 1][q - 'A'] + (a != str[i]));
                }
            }
            r = min(r, dp[i][a - 'A']);
        }                   
    }

    cout << make_ans(str.length() - 1, m, '#') << endl;

    cout << str;

    return 0;
}