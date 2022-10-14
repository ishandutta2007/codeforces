#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        int npom = n;
        int k3 = 0, k2 = 0;
        while(npom % 3 == 0)
        {
            npom /= 3;
            k3++;
        }
        while(npom % 2 == 0)
        {
            npom /= 2;
            k2++;
        }
        if(npom > 1 || k2 > k3)
        {
            cout << -1 << endl;
            continue;
        }
        cout << k3+k3-k2 << endl;
    }
}