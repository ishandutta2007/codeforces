#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << (a ^ b) << endl;
    }
    return 0;
}