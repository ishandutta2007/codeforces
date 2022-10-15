#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n; cin >> n;
    for (int t = 0; t < n; ++t)
    {
        int s, i, e; cin >> s >> i >> e;

        // int count = 0;

        // for (int b = 0; s + e - i > 2*b && b <= e; ++b)
        //     count += 1;

        int temp = s+e-i;

        if (temp > 0)
        {
            cout << min(e + 1, 1 + (temp - 1)/2) << endl;
        }

        else
            cout << 0 << endl;
    }
    return 0;
}