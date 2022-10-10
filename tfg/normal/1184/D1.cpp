#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <assert.h>

using namespace std;

int kolx[515];
int koly[515];

int main()
{
    int n,k,m,t;
    cin >> n >> k >> m >> t;
    while(t--)
    {
        int T;
        cin >> T;
        if (T)
        {
            int x;
            cin >> x;
            ++n;
            if (x<=k)
                ++k;
        }
        else
        {
            int x;
            cin >> x;

            if (x<k)
            {
                k-=x;
                n-=x;
            } else {
                n=x;
            }

        }

        cout << n << ' ' << k << endl;
    }
    return 0;
}