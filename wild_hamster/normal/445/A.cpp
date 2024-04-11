#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll k,j,x,y,n,m,cnt,i,a[1005][1005];
string s;

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            {
                 char c;
                 cin >> c;
                 if (c == '.') a[i][j] = (i+j)%2+1;
            }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        if (a[i][j] == 1)
           cout << "B";
        else if (a[i][j] == 2)
             cout << "W";
        else
            cout << "-";
        cout << endl;
    }
    return 0;
}