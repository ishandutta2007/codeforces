#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[100];
int use[100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    
    int cnt = 0;
    if (k >= m)
    {
        cout << 0;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cnt++;               
        if (k)
        {
            m -= a[i];
            k--; 
        }
        else
        {
            for (int s = n - 1; s > i; s--)
            {
                if (use[s] != a[s])
                {
                    use[s]++;
                    m++;
                    break;
                }
            }   
            m -= a[i];
        }


        if (m - k <= 0)
            break;
    }

    cout << (m - k > 0 ? -1 : cnt);

    return 0;
}