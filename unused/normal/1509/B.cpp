#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str >> str;
        
        int c = 0, d = 0;
        bool wrong = false;
        for (char ch : str)
        {
            if (ch == 'T')
            {
                ++c;
            }
            else
            {
                if (c == d)
                {
                    wrong = true;
                    break;
                }
                ++d;
            }
        }
        if (c != d * 2) wrong = true;
        reverse(str.begin(), str.end());
        c = 0; d = 0;
        for (char ch : str)
        {
            if (ch == 'T')
            {
                ++c;
            }
            else
            {
                if (c == d)
                {
                    wrong = true;
                    break;
                }
                ++d;
            }
        }
        if (wrong) cout << "NO\n";
        else cout << "YES\n";
    }
}