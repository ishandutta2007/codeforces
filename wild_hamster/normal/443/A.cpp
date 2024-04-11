#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
ll i,a[500],rez;
string s;
int main()
{
    while (cin >> s)
    {
        //if (s == "yazhka") break;
        for (i = 0; i < s.size(); i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                a[s[i]] = 1;
    }
    rez = 0;
    for (i = 'a'; i <= 'z'; i++)
        if (a[i]) rez++;
    cout << rez << endl;
    return 0;
}