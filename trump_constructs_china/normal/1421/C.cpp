#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[120000];
int n;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s + 1;
    n = strlen(s + 1);
    cout << 3 << "\n";
    cout << "L 2\n";
    n++;
    cout << "R 2\n";
    n += (n - 2);
    cout << "R " << n - 1 << "\n";
    return 0;
}