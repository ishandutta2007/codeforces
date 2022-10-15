#include "bits/stdc++.h"

using namespace std;

int main(int argc, char *argv[])
{
    int a[4];

    for (int i = 0; i < 4; ++i)
        cin >> a[i];

    if (
        (a[0] + a[1] == a[2] + a[3]) ||
        (a[0] + a[2] == a[1] + a[3]) ||
        (a[0] + a[3] == a[1] + a[2]) ||
        (a[0] + a[1] + a[2] == a[3]) ||
        (a[1] + a[2] + a[3] == a[0]) ||
        (a[2] + a[3] + a[0] == a[1]) ||
        (a[3] + a[0] + a[1] == a[2])
    )
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}