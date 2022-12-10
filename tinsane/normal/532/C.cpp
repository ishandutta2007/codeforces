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
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

#pragma comment(linker, "/STACK:1677721600")

int main()
{
    ios_base::sync_with_stdio(0);
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if(xb <= xa && yb <= ya)
    {
        cout << "Vasiliy";
        return 0;
    }
    if(xa <= xb && ya <= yb)
    {
        cout << "Polycarp";
        return 0;
    }
    if(xa < xb)
    {
        if(xb - xa < ya)
            cout << "Vasiliy";
        else
            cout << "Polycarp";
        return 0;
    }
    if(yb - ya < xa)
        cout << "Vasiliy";
    else
        cout << "Polycarp";
    return 0;
}