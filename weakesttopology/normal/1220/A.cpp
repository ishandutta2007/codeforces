#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n; cin >> n;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        char temp; cin >> temp;
        count += temp == 'n';
    }

    for (int i = 0; i < count; ++i)
        cout << 1 << " ";

    for (int i = 0; i < (n - count * 3) / 4; ++i)
    {
        cout << 0 << " ";
    }

    return 0;
}