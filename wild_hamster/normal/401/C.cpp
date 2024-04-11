#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
ll i,j,n,rez,m,y,z,a[100500],x,k;
string s;
int main()
{
    cin >> n >> m;
    if ((n+1)*2 < m||n > m+1)
    {
       cout << -1 << endl;
       return 0;
    } else
    if (n == m+1)
    {
     cout << '0';
     for (i = 0; i < m; i++)
         cout << "10";
     cout << endl;
     return 0;
    }
    else
    {
        for (i = 0; i < n+m; i++)
            s.push_back('1');
        ll tmp = -1;
        k = n;
        for (i = 0; i < n; i++)
        {
            tmp += m/(k+1) + 1;
            m -= m/(k+1);
            k--;
            s[tmp] = '0';
        }
    }
    cout << s << endl;
    return 0;
}