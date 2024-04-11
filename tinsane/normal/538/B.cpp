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
#include <unordered_set>
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e4 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    string n;
    int ma(0);
    cin >> n;
    for(int i(0); i < n.size(); ++i)
        ma = max(ma, n[i] - '0');
    cout << ma << '\n';
    while(ma--)
    {
        int i(0);
        for(;n[i] == '0'; ++i);
        for(; i < n.size(); ++i)
            if(n[i] != '0')
                cout << '1', --n[i];
            else
                cout << '0';
        cout << ' ';
    }
    return 0;
}