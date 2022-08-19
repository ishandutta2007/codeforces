#include <iostream>
#include <string>
using namespace std;

int n, a, b;
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'x')
            a++;
        else
            b++;
    if (a > b)
    {
        printf("%d\n", (a - b) / 2);
        for (int i = 0; i < n; i++)
        {
            if ((a != b) && s[i] == 'x')
            {
                s[i] = 'X';
                a--;
                b++;
            }
        }
        cout << s << endl;
    }
    else
    {
        printf("%d\n", (b - a) / 2);
        for (int i = 0; i < n; i++)
        {
            if ((a != b) && s[i] == 'X')
            {
                s[i] = 'x';
                a++;
                b--;
            }
        }
        cout << s << endl;
    }
//  cin >> n;
    return 0;
}