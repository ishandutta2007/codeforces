#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 100100;

char s[5];

int main()
{
//    freopen ("in.txt", "r", stdin);
    cin >> s;
    int res = 8;
    if (s[0] == 'a' || s[0] == 'h') res = res / 2 + 1;
    if (s[1] == '1' || s[1] == '8') res = res / 2 + 1;
    cout << res << endl;
    return 0;
}