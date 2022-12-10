#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

char xor(char a, char b)
{
    a -= '0';
    b -= '0';
    return (a ^ b) + '0';
}

int main()
{
    ios_base::sync_with_stdio(0);
    string a, b, c("");
    int cnt(0);
    cin >> a >> b;
    for(int i(0); i < a.size(); ++i)
        c += xor(a[i], b[i]), cnt += c[i] == '1';
    if(cnt & 1)
    {
        cout << "impossible";
        return 0;
    }
    for(int i(0), j(0); i < c.size(); ++i)
    if(c[i] == '1')
    {
        if(j < cnt / 2)
            c[i] = a[i];
        else
            c[i] = b[i];
        ++j;
    }
    cout << c;
    return 0;
}