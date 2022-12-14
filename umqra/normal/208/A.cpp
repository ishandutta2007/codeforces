#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    string str;
    cin >> str;
    bool start = false;
    for ( int i = 0; i < str.length();  )
    {
        if ( str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B' )
        {
            i += 3;
            if ( start )
                cout << " ";
            start = 0;
        }
        else
        {   
            cout << str[i];
            i++;
            start = 1;
        }
    }
    return 0;
}