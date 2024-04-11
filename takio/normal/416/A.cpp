#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, e = 2e9, f = -2e9;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char s[4], c;
        int t;
        scanf ("%s", s);
//        cout << s;
        cin >> t >> c;
        if (c == 'N')
        {
            if(s[0] == '>') s[0] = '<';
            else s[0] = '>';
            if(s[1] == '=') s[1] = 0;
            else s[1]= '=';
        }
        if (s[1] != '=')
        {
            if(s[0] == '>') t++;
            else t--;
        }
        if (s[0] == '>') f = max (f, t);
        else e = min (e, t);
    }
    if(f <= e)cout << f;
    else cout << "Impossible";
}