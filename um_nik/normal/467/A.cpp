#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int ans;
int x, y;


int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (y - x >= 2) ans++;
    }
    cout << ans << endl;

    return 0;
}