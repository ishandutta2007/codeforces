#include <iostream>
#include <string>
using namespace std;

string s, t;
int n, ans;

int main()
{
    cin >> s;
    cin >> t;
    n = s.length();
    ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (s[i] == '(')
        {
            if (t[i] == '[')
                ans--;
            if (t[i] == '8')
                ans++;
        }
        if (s[i] == '[')
        {
            if (t[i] == '8')
                ans--;
            if (t[i] == '(')
                ans++;
        }
        if (s[i] == '8')
        {
            if (t[i] == '(')
                ans--;
            if (t[i] == '[')
                ans++;
        }
    }
    if (ans > 0)
        printf("TEAM 1 WINS\n");
    if (ans < 0)
        printf("TEAM 2 WINS\n");
    if (ans == 0)
        printf("TIE\n");
//  cin >> n;
    return 0;
}