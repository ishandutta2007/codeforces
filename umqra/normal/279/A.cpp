#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};

int c[4];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int x, y;
    cin >> x >> y;
        
    c[0] = c[1] = 1;
    c[2] = c[3] = 2;
    int stX = 0, stY = 0;
    int cnt = 0;
    int ind = 0;
    while (1)
    {
        int nX = stX + DX[ind] * c[ind];
        int nY = stY + DY[ind] * c[ind];     
                                
        if (nX == x && nY == y)
        {
            cout << cnt;
            return 0;
        }
         
        if (nX == stX)
        {
            int d = (nY - stY > 0 ? 1 : -1);
            for (int i = stY; i != nY; i += d)
            {
                if (stX == x && i == y)
                {
                    cout << cnt;
                    return 0;
                }
            }
        }

        else
        {
            int d = (nX - stX > 0 ? 1 : -1);
            for (int i = stX; i != nX; i += d)
            {
                if (i == x && stY == y)
                {            
                    cout << cnt;
                    return 0;
                }
            }
        }                    

        cnt++;
        c[ind] += 2;
        ind = (ind + 1) % 4;
        stX = nX;
        stY = nY;
    }

    return 0;
}