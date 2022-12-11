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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = 1e3 + 10;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, mas[100000], nek;
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    if(mas[n - 1])
    {
        cout << "NO";
        return 0;
    }
    if(n == 1)
    {
        cout << "YES\n0";
        return 0;
    }
    for(nek = 0; mas[nek]; ++nek);
    if(nek == n - 2)
    {
        cout << "NO";
        return 0;
    }
    if(nek == n - 1)
    {
        cout << "YES\n";
        for(int i(0); i < n - 1; ++i)
            cout << "1->";
        cout << 0;
        return 0;
    }
    cout << "YES\n";
    cout << '(';
    for(int i(0); mas[i]; ++i)
        cout << "1->";
    cout << "(0->(";
    for(int i(nek + 1); i < n - 2; ++i)
        cout << mas[i] << "->";
    cout << mas[n - 2] << ")))->0"; 
    return 0;
}