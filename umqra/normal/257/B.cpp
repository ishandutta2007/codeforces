#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = (int)1e6;

int a[N];
int b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
                        
    a[0] = 0;
    b[0] = 1;
    int x1 = n - 1, y1 = m;
    int x2 = n, y2 = m - 1;  
    for (int i = 1; i < n + m; i++)
    {       
        if (x1 == 0)
        {
            a[i] = 1;
            y1--;
        }
        else if (y1 == 0)
        {
            a[i] = 0;
            x1--;
        }
        else
        {                
            if (i % 4 == 1 || i % 4 == 2)
            {
                a[i] = 1;
                y1--;
            }
            else
            {
                a[i] = 0;
                x1--;
            } 
        }            
    }

    for (int i = 1; i < n + m; i++)
    {       
        if (x2 == 0)
        {
            b[i] = 1;
            y2--;
        }
        else if (y2 == 0)
        {
            b[i] = 0;
            x2--;
        }
        else
        {                
            if (i % 4 == 1 || i % 4 == 2)
            {
                b[i] = 0;
                x2--;
            }
            else
            {
                b[i] = 1;
                y2--;
            } 
        }            
    }


    int res1 = 0, res2 = 0;
    for (int i = 1; i < n + m; i++)
    {
        if (a[i] != a[i - 1])
            res2++;
        else
            res1++;
    }                    
  
    int p1 = 0, p2 = 0;
    for (int i = 1; i < n + m; i++)
    {
        if (b[i] != b[i - 1])
            p2++;
        else
            p1++;
    }

    if (res1 > p1)
        cout << res1 << ' ' << res2;
    else if (res1 == p1 && res2 < p2)
        cout << res1 << ' ' << res2;
    else
        cout << p1 << ' ' << p2;
                     
    return 0;
}